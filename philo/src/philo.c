/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:41:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/28 13:31:22 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int	stop_threads(t_data *data)
{
	static int	i;

	data->sim = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (i);
		pthread_mutex_destroy(&data->forks[i].mtx);
		i++;
	}
	free(data->forks);
	free(data->philos);
	free(data);
	exit(0);
}

int	philosophers(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	data->goal = data->nb_philo;
	while (i < data->nb_philo)
	{
		data->i = i;
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			return (i);
		i++;
	}
	data->start = get_time(data);
	data->sim = 1;
	while (data->sim)
		;
	return (0);
}
