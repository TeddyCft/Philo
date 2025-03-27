/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/27 18:27:36 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "structs.h"

// UTILS

void			*ft_calloc(size_t nmemb, size_t size);
int				ft_atoi(const char *nptr);
unsigned long	get_time(t_data *data);

// PHILO

int				philosophers(t_data *data, t_philo *philos);
int				stop_threads(t_data *data, t_philo *philos);

//ROUTINE

void			*routine(void *data);

//EAT

int				can_eat(t_philo *philos, t_data *data);
void			drop_forks(t_philo *philos, t_data *data);

#endif