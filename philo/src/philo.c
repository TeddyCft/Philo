/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:41:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/21 20:13:28 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

int	philo_display(long time, t_philo philo, int fork)
{
	if (fork)
		return (printf("%ld %d has taken a fork\n", time, philo.id));
	if (philo.status == EAT)
		return (printf("%ld %d is eating\n", time, philo.id));
	if (philo.status == SLEEP)
		return (printf("%ld %d is sleeping\n", time, philo.id));
	if (philo.status == THINK)
		return (printf("%ld %d is thinking\n", time, philo.id));
	if (philo.status == DIE)
		return (printf("%ld %d died\n", time, philo.id));
	return (0);
}

void	philo_status(t_philo *philo, int i, int status)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo[i].status = status;
	philo_display(time.tv_usec / 1000, philo[i], 0);
}

int	philosophers(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		
	}
	return (0);
}
