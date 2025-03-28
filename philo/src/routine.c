/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:22:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/28 13:36:01 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> 

void	phi_sleep(t_philo *philos, t_data *data)
{
	unsigned long	time;

	time = get_time(data);
	philos->status = SLEEP;
	printf("\033[0;34m%ld %d is sleeping\033[0m\n", time, philos->id);
	usleep(data->tt_sleep * 1000);
}

int	think(t_philo *philos, unsigned long time)
{
	if (philos->status != THINK)
	{
		philos->status = THINK;
		printf("\033[0;36m%ld %d is thinking\033[0m\n", time, philos->id);
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

int	eat(t_philo *philos, t_data *data, unsigned long time)
{
	if (!can_eat(philos, data))
		return (0);
	printf("\033[0;32m%ld %d has taken a fork\033[0m\n", time, philos->id);
	printf("\033[0;32m%ld %d has taken a fork\033[0m\n", time, philos->id);
	philos->status = EAT;
	philos->last_meal = time;
	printf("\033[0;32m%ld %d is eating\033[0m\n", time, philos->id);
	usleep(data->tt_eat * 1000);
	drop_forks(philos, data);
	has_eaten(philos, data);
	return (1);
}

unsigned long	get_time(t_data *data)
{
	struct timeval	time;
	unsigned long	ret;

	gettimeofday(&time, NULL);
	ret = ((time.tv_sec * 1000) + (time.tv_usec / 1000) - data->start);
	(void) data;
	return (ret);
}

void	*routine(void *arg)
{
	unsigned long	time;
	t_philo			*philo;

	philo = arg;
	while (!philo->data->sim)
		;
	philo->last_meal = philo->data->start;
	while (philo->data->sim)
	{
		time = get_time(philo->data);
		if (time >= (unsigned long)(philo->last_meal + philo->data->tt_die))
			break ;
		if (!eat(philo, philo->data, time) && philo->data->sim)
			think(philo, time);
	}
	time = get_time(philo->data);
	if (philo->data->sim)
		printf("\033[0;31m%ld %d is dead\033[0m\n", time, philo->id);
	stop_threads(philo->data);
	return (0);
}
