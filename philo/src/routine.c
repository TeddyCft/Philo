/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:22:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/30 16:10:51 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> 

void	print_status(t_status stat, t_philo philos, size_t time, int last)
{
	pthread_mutex_lock(&philos.data->print_mtx);
	if (!philos.data->sim)
	{
		pthread_mutex_unlock(&philos.data->print_mtx);
		return ;
	}
	if (last)
		philos.data->sim = 0;
	if (stat == EAT)
		printf("\033[0;36m%ld %d is eating\033[0m\n", time, philos.id);
	if (stat == SLEEP)
		printf("\033[0;34m%ld %d is sleeping\033[0m\n", time, philos.id);
	if (stat == FORK)
	{
		printf("\033[0;32m%ld %d has taken a fork\033[0m\n", time, philos.id);
		printf("\033[0;32m%ld %d has taken a fork\033[0m\n", time, philos.id);
	}
	if (stat == THINK)
		printf("\033[0;35m%ld %d is thinking\033[0m\n", time, philos.id);
	if (stat == DIE)
		printf("\033[0;31m%ld %d is dead\033[0m\n", time, philos.id);
	pthread_mutex_unlock(&philos.data->print_mtx);
}

void	phi_sleep(t_philo *philos, t_data *data)
{
	size_t	time;

	time = get_time(data);
	philos->status = SLEEP;
	print_status(SLEEP, *philos, time, 0);
	usleep(data->tt_sleep * 1000);
}

int	think(t_philo *philos, size_t time)
{
	if (philos->status != THINK)
	{
		philos->status = THINK;
		if (philos->data->sim)
			print_status(THINK, *philos, time, 0);
		return (0);
	}
	return (0);
}

void	has_eaten(t_philo *philo, t_data *data)
{
	philo->to_eat--;
	if (philo->to_eat == 0)
	{
		pthread_mutex_lock(&data->goal_mtx);
		if (data->goal != -1)
		{
			data->goal--;
			pthread_mutex_unlock(&data->goal_mtx);
			if (!data->goal)
				stop_threads(data);
		}
		pthread_mutex_unlock(&data->goal_mtx);
	}
	phi_sleep(philo, data);
}

int	eat(t_philo *philos, t_data *data, size_t time)
{
	if (!can_eat(philos, data))
		return (0);
	print_status(FORK, *philos, time, 0);
	philos->status = EAT;
	philos->last_meal = time;
	if (philos->to_eat == 1 && data->goal == 1)
		print_status(EAT, *philos, time, 1);
	else
		print_status(EAT, *philos, time, 0);
	usleep(data->tt_eat * 1000);
	drop_forks(philos, data);
	has_eaten(philos, data);
	return (1);
}

size_t	get_time(t_data *data)
{
	struct timeval	time;
	size_t			ret;

	gettimeofday(&time, NULL);
	ret = ((time.tv_sec * 1000) + (time.tv_usec / 1000) - data->start);
	(void) data;
	return (ret);
}

void	*routine(void *arg)
{
	size_t	time;
	t_philo	*philo;

	philo = arg;
	while (!philo->data->sim)
		;
	philo->last_meal = 0;
	while (philo->data->sim)
	{
		time = get_time(philo->data);
		if (time >= (size_t)(philo->last_meal + philo->data->tt_die))
			break ;
		if (!eat(philo, philo->data, time) && philo->data->sim)
			think(philo, time);
	}
	time = get_time(philo->data);
	if (philo->data->sim)
		print_status(DIE, *philo, time, 1);
	stop_threads(philo->data);
	return (0);
}
