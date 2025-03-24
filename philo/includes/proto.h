/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:45:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:48 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "structs.h"

// UTILS

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);

// PHILO

int		philosophers(t_data *data, t_philo *philo);

//ROUTINE

int		routine(t_data *data, t_philo *philos, int i);

#endif