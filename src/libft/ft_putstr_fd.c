/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:25:02 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:46:30 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Écrit la chaîne de caractères ’s’ sur le descripteur de fichier donné. */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*(char *)s)
		write(fd, s++, 1);
}

/* int	main()
{
	ft_putstr_fd("Salut", 1);
} */