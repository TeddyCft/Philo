/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:22:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 16:13:50 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void	phi_sleep(t_philo *philos, int i, long time, t_data *data)
{
	philos->status = SLEEP;
	printf("%ld %d is sleeping\n", time, philos[i].id);
	usleep(data->tt_die);
}

void	think(t_philo *philos, int i, long time)
{
	if (philos[i].status != THINK)
	{
		philos[i].status = THINK;
		printf("%ld %d is thinking\n", time, philos[i].id);
	}
}

int	eat(t_philo *philos, t_data *data, int i, long time)
{
	if (!can_eat(philos, i, data))
		return (0);
	printf("%ld %d has taken a fork\n", time, philos[i].id);
	printf("%ld %d has taken a fork\n", time, philos[i].id);
	philos[i].status = EAT;
	philos[i].last_meal = time;
	printf("%ld %d is eating\n", time, philos[i].id);
	usleep(data->tt_eat);
	drop_forks(philos, i, data);
	return (1);
}

void	*routine(void *arg)
{
	struct timeval	time;
	t_data			*data;
	int				i;

	data = arg;
	i = data->i;
	printf("created philosopher n[%d]\n", i);
	while (data->philos[i].status != DIE)
	{
		gettimeofday(&time, NULL);
		if ((time.tv_usec / 1000) - data->philos[i].last_meal >= data->tt_die)
			break ;
		if (!eat(data->philos, data, i, time.tv_usec / 1000))
			think(data->philos, i, time.tv_usec / 1000);
		else
		{
			data->philos[i].to_eat--;
			if (data->philos[i].to_eat == 0)
			{
				if (data->goal)
				{
					data->goal--; //a proteger avec un mutex ??
					if (!data->goal)
						stop_threads(data, data->philos);
				}
				data->philos[i].to_eat--;
			}
			phi_sleep(data->philos, i, time.tv_usec / 1000, data);
		}
	}
	gettimeofday(&time, NULL);
	printf("%ld %d is dead\n", time.tv_usec / 1000, data->philos[i].id);
	stop_threads(data, data->philos);
	return (0);
}
