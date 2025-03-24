/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:28:11 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 13:28:35 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

///!\\\ BIEN PROTEGER TOUT CA AVEC UN MUTEX
void	drop_forks(t_philo *philos, int i, t_data *data)
{
	int	next;

	next = philos[i].id;
	if (philos[i].id == data->nb_philo)
		next = 0;
	if (!data->forks[i].owner && !data->forks[next].owner)
	{
		pthread_mutex_lock(&data->forks[i].mtx);
		(&data->forks[next].mtx);
		data->forks[i].owner = 0;
		data->forks[next].owner = 0;
		pthread_mutex_unlock(&data->forks[i].mtx);
		(&data->forks[next].mtx);
	}
}

///!\\\ BIEN PROTEGER TOUT CA AVEC UN MUTEX
int	can_eat(t_philo *philos, int i, t_data *data)
{
	int	next;

	next = philos[i].id;
	if (data->nb_philo == 1)
		return (0);
	if (philos[i].id == data->nb_philo)
		next = 0;
	if (!data->forks[i].owner && !data->forks[next].owner)
	{
		pthread_mutex_lock(&data->forks[i].mtx);
		pthread_mutex_lock(&data->forks[next].mtx);
		data->forks[i].owner = philos[i].id;
		data->forks[next].owner = philos[i].id;
		pthread_mutex_unlock(&data->forks[i].mtx);
		pthread_mutex_unlock(&data->forks[next].mtx);
		return (1);
	}
	else
		return (0);
}
