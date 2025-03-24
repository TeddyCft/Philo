/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:41:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 14:09:23 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

int	stop_threads(t_data *data, t_philo *philos)
{
	static int	i;

	while (i < data->nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (i);
		pthread_mutex_destroy(&data->forks[i].mtx);
		i++;
	}
	return (0);
}

int	philosophers(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, \
		(void *)(*routine)(data, philos, i), NULL))
			return (i);
		i++;
	}
	if (stop_threads(data, philos))
		return (-1);
	return (0);
}
