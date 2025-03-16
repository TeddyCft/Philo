/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:30:48 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:45:40 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Écrit La chaîne de caractères ’s’ sur le descripteur de fichier donné suivie
d’un retour à la ligne. */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*(char *)s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/* int	main()
{
	ft_putendl_fd("Croissan is good", 1);
} */