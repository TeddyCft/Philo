/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:34:08 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:46:13 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Écrit l’entier ’n’ sur le descripteur de fichier donné. */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return ((void)write(fd, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
}

/* int	main(void)
{
	ft_putnbr_fd(10, 1);
	return (0);
} */
