/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:22:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/21 20:00:06 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

void	sleep(t_philo *philos, int i, long time)
{
	printf("%ld %d is sleeping\n", time, philos[i].id);
	//wait tts
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
	philos[i].status = EAT;
	philos[i].last_meal = time;
	printf("%ld %d is eating\n", time, philos[i].id);
	//wait data.tt_eat
	drop_forks(data, philos[i].id);
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
			sleep(philos, i, time.tv_usec / 1000);
		}
	}
	gettimeofday(&time, NULL);
	printf("%ld %d is dead\n", time.tv_usec / 1000, philos[i].id);
	return (1);
}
