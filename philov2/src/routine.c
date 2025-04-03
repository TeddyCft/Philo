/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:22:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/04/02 13:02:20 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> 

void	drop_forks(t_philo *philos, t_data *data)
{
	int	next;
	int	i;

	i = philos->id - 1;
	next = philos->id;
	if (philos->id == data->nb_philo)
		next = 0;
	data->forks[i].owner = 0;
	data->forks[next].owner = 0;
	pthread_mutex_unlock(&data->forks[i].mtx);
	pthread_mutex_unlock(&data->forks[next].mtx);
}

int	can_eat(t_philo *philos, t_data *data)
{
	int	next;
	int	i;

	i = philos->id - 1;
	next = philos->id;
	if (data->nb_philo == 1)
		return (0);
	if (philos->id == data->nb_philo)
		next = 0;
	pthread_mutex_lock(&data->forks_mtx);
	if (!data->forks[i].owner && !data->forks[next].owner)
	{
		pthread_mutex_lock(&data->forks[i].mtx);
		pthread_mutex_lock(&data->forks[next].mtx);
		data->forks[i].owner = philos->id;
		data->forks[next].owner = philos->id;
		pthread_mutex_unlock(&data->forks_mtx);
		return (1);
	}
	pthread_mutex_unlock(&data->forks_mtx);
	return (0);
}

int	eat(t_philo *philo, t_data *data, size_t time)
{
	if (!can_eat(philo, data))
		return (0);
	change_status(philo, FORK);
	philo->last_meal = time;
	change_status(philo, EAT);
	usleep(data->tt_eat * 1000);
	drop_forks(philo, data);
	change_status(philo, SLEEP);
	usleep(data->tt_sleep * 1000);
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
		{
			change_status(philo, DIE);
			break ;
		}
		if (!eat(philo, philo->data, time) && philo->data->sim)
			change_status(philo, THINK);
	}
	return (0);
}
