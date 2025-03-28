/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:55:22 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/28 13:22:12 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

void	*mfail(void)
{
	write(2, "Error : malloc failed\n", 23);
	return (NULL);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (i);
}

int	arg_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (write(2, "Error : argument count is invalid\n", 35));
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (write(2, "Error : argument is invalid\n", 29));
		if (ft_atoi(argv[1]) < 1)
			return (write(2, "Error : must be at least 1 philosopher\n", 40));
		if (argc == 6 && ft_atoi(argv[5]) < 0)
			return (write(2, "Error : philosopher can't eat negative times\n", 46));
		i++;
	}
	return (0);
}

t_fork	*fill_forks(t_data *data, int nb)
{
	t_fork	*new;
	int		i;

	new = 0;
	new = ft_calloc(nb + 1, sizeof(t_fork));
	if (!new)
		return (NULL);
	data->forks = new;
	i = 0;
	while (i < nb)
	{
		// data->forks[i].mtx = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(&data->forks[i].mtx, NULL);
		new[i].id = i + 1;
		new[i].owner = 0;
		i++;
	}
	return (new);
}

t_philo	*get_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = ft_calloc(data->nb_philo + 1, sizeof(t_philo));
	if (!philos)
		return (NULL);
	while (i < data->nb_philo)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].status = START;
		if (data->goal)
			philos[i].to_eat = data->goal;
		philos[i].last_meal = 0;
		i++;
	}
	return (philos);
}

t_data	*fill_data(char **argv, int argc)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (mfail());
	new->sim = 0;
	new->start = 0;
	new->nb_philo = ft_atoi(argv[1]);
	new->tt_die = ft_atoi(argv[2]);
	new->tt_eat = ft_atoi(argv[3]);
	new->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		pthread_mutex_init(&new->goal_mtx, NULL);
		new->goal = ft_atoi(argv[5]);
	}
	else
		new->goal = -1;
	pthread_mutex_init(&new->forks_mtx, NULL);
	new->i = 0;
	new->forks = fill_forks(new, new->nb_philo);
	if (!new->forks)
		return (free(new), mfail());
	return (new);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		ret;

	if (arg_check(argc, argv))
		return (1);
	data = fill_data(argv, argc);
	if (!data)
		return (1);
	data->philos = get_philos(data);
	if (!data->philos)
		return (free(data->forks), free(data), 1);
	ret = philosophers(data, data->philos);
	if (ret)
		write(2, "Error : thread failed\n", 23);
	free(data->forks);
	free(data);
	return (0);
}
