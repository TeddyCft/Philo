/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:31:31 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:40:50 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compte le nombre d’éléments de la liste. */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (!(temp))
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i + 1);
}
