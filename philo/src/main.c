/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:55:22 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/21 20:18:27 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
	if (argc != 6)
		return (write(2, "Error : argument count is invalid\n", 35));
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (write(2, "Error : argument is invalid\n", 29));
		if (ft_atoi(argv[1]) < 1)
			return (write(2, "Error : must be at least 1 philosopher\n", 40));
		i++;
	}
	return (0);
}

t_data	*fill_data(char **argv)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (mfail());
	new->nb_philo = ft_atoi(argv[1]);
	new->tt_die = ft_atoi(argv[2]);
	new->tt_eat = ft_atoi(argv[3]);
	new->tt_sleep = ft_atoi(argv[4]);
	new->goal = ft_atoi(argv[5]);
	new->forks = fill_forks(new->nb_philo);
	if (!new->forks)
		return (free(new), mfail());
	return (new);
}

t_philo	*get_philos(t_data data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = ft_calloc(data.nb_philo + 1, sizeof(t_philo));
	if (!philos)
		return (NULL);
	while (i < data.nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].status = START;
		philos[i].to_eat = data.goal;
		philos[i].last_meal = 0;
		i++;
	}
	return (philos);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;

	if (arg_check(argc, argv))
		return (1);
	data = fill_data(argv);
	if (!data)
		return (1);
	philos = get_philos(*data);
	if (!philos)
		return (free(data), 1);
	philosophers(data, philos);
	free(data);
	free(philos);
	return (0);
}

/* to free

-(main) data

*/