/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:41:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 16:22:08 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


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
	free(data->forks);
	free(data->philos);
	free(data);
	exit(0);
}

int	philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->i = i;
		if (pthread_create(&data->philos[i].thread, NULL, &routine, data))
			return (i);
		usleep(100);
		i++;
	}
	if (stop_threads(data, data->philos))
		return (-1);
	return (0);
}
