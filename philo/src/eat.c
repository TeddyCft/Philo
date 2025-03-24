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

// drop_fork() : une fonction qui permet de remettre le owner des deux fork portees par le phi a 0;

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
		pthread_mutex_lock(&data->forks[next].mtx);
		data->forks[i].owner == 0;
		data->forks[next].owner == 0;
		pthread_mutex_unlock(&data->forks[i].mtx);
		pthread_mutex_unlock(&data->forks[next].mtx);
	}
}

// can_eat() : verifie si les fourchettes sont disponibles pour le phi, change leur owner auquel cas et print que le owner a prit des forks

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
		data->forks[i].owner == philos[i].id;
		data->forks[next].owner == philos[i].id;
		pthread_mutex_unlock(&data->forks[i].mtx);
		pthread_mutex_unlock(&data->forks[next].mtx);
		return (1);
	}
	else
		return (0);
}
