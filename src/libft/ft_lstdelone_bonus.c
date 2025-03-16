/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:40:10 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 11:01:39 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!(lst) || (!(del)))
		return ;
	del(lst->content);
	free(lst);
}

/* int	main(int argc, char const *argv[])
{
	ft_lstdelon(lst, &del);
	return (0);
} */
