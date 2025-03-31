/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:12:44 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/31 18:47:32 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// NO COLORS
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
		printf("%ld %d is eating\n", time, philos.id);
	if (stat == SLEEP)
		printf("%ld %d is sleeping\n", time, philos.id);
	if (stat == FORK)
	{
		printf("%ld %d has taken a fork\n", time, philos.id);
		printf("%ld %d has taken a fork\n", time, philos.id);
	}
	if (stat == THINK)
		printf("%ld %d is thinking\n", time, philos.id);
	if (stat == DIE)
		printf("%ld %d is dead\n", time, philos.id);
	pthread_mutex_unlock(&philos.data->print_mtx);
}

// COLORS
/* void	print_status(t_status stat, t_philo philos, size_t time, int last)
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
} */

void	change_status(t_philo *philo, int status)
{
	printf("trying to change status in philo[%d] for stat [%d]\n", philo->id, status);
	pthread_mutex_lock(&philo->stat_mtx);
	philo->status = status;
	pthread_mutex_unlock(&philo->stat_mtx);
}

void	check_status(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo[i].stat_mtx);
	if (philo[i].prev_stat != philo[i].status)
	{
		philo[i].prev_stat = philo[i].status;
		pthread_mutex_unlock(&philo[i].stat_mtx);
		if (philo[i].prev_stat == EAT)
			philo[i].to_eat--;
		if (!philo[i].to_eat)
		{
			philo[i].to_eat--;
			pthread_mutex_lock(&data->goal_mtx);
			data->goal--;
			if (data->goal == 0)
			{
				pthread_mutex_unlock(&data->goal_mtx);
				print_status (philo[i].prev_stat, *philo, get_time(data), 1);
			}
			pthread_mutex_unlock(&data->goal_mtx);
		}
		else if (philo[i].prev_stat == DIE)
			print_status(philo[i].prev_stat, *philo, get_time(data), 1);
		else
			print_status(philo[i].prev_stat, *philo, get_time(data), 0);
	}
}

int	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo && data->sim)
	{
		printf("monitoring [%d] -- status = %d\n", i, data->philos[i].status);
		if (!data->sim)
			return (stop_threads(data));
		check_status(data, &data->philos[i], i);
		i++;
	}
	return (1);
}