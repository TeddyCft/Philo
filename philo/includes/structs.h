/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:39 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 14:08:38 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef enum e_status
{
	START = 0,
	THINK = 1,
	EAT = 2,
	SLEEP = 3,
	DIE = 4
}	t_status;

typedef struct s_fork
{
	int				id;
	int				owner;
	pthread_mutex_t	mtx;
}	t_fork;

typedef struct s_data
{
	int		nb_philo;
	int		tt_sleep;
	int		tt_eat;
	int		tt_die;
	int		goal;
	t_fork	*forks;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			to_eat;
	int			status;
	long		last_meal;
}	t_philo;

#endif