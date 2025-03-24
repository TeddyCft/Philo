/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:22:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 13:40:57 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

void	sleep(t_philo *philos, int i, long time, t_data *data)
{
	philos->status = SLEEP;
	printf("%ld %d is sleeping\n", time, philos[i].id);
	usleep(data->tt_die);
}

void	think(t_philo *philos, int i, long time)
{
	if (philos[i].status == EAT)
	{
		philos[i].status == THINK;
		printf("%ld %d is thinking\n", time, philos[i].id);
	}
}

int	eat(t_philo *philos, t_data *data, int i, long time)
{
	if (!can_eat(philos, i, *data))
		return (0);
	printf("%ld %d has taken a fork\n", time, philos[i].id);
	printf("%ld %d has taken a fork\n", time, philos[i].id);
	philos[i].status = EAT;
	philos[i].last_meal = time;
	printf("%ld %d is eating\n", time, philos[i].id);
	usleep(data->tt_eat);
	drop_forks(philos, i, *data);
	return (1);
}

int	routine(t_data *data, t_philo *philos, int i)
{
	struct timeval	time;

	while (philos[i].status != DIE)
	{
		gettimeofday(&time, NULL);
		if ((time.tv_usec / 1000) - philos[i].last_meal >= data->tt_die)
			break ;
		if (!eat(philos, data, i, time.tv_usec / 1000))
			think(philos, i, time.tv_usec / 1000);
		else
		{
			philos[i].to_eat--;
			if (philos[i].to_eat == 0)
			{
				data->goal--; //a proteger avec un mutex ??
				philos[i].to_eat--;
			}
			sleep(philos, i, time.tv_usec / 1000, data);
		}
	}
	gettimeofday(&time, NULL);
	printf("%ld %d is dead\n", time.tv_usec / 1000, philos[i].id);
	return (1);
}
