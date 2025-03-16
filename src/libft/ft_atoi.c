/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:35:45 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:18:54 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The atoi() function converts the initial portion of the string pointed to by
nptr to int. */

#include "libft.h"

static int	is_neg(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	return (1);
}

static int	space_check(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		i++;
	}
	while (nptr[i] == '0')
		i++;
	if (!(nptr[i] >= '1' && nptr[i] <= '9'))
		return (-1);
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			nb;
	int			i;
	int			l;
	long int	p;

	p = 1 * (is_neg(nptr));
	nb = 0;
	i = space_check(nptr);
	l = 0;
	if (i < 0)
		return (0);
	while (nptr[i + l] >= '0' && nptr[i + l] <= '9')
	{
		l++;
		p *= 10;
	}
	while (l > 0)
	{
		p /= 10;
		nb = nb + ((nptr[i] - '0') * p);
		l--;
		i++;
	}
	return (nb);
}

/* #include<stdio.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n", ft_atoi(argv[1]));
	printf("%d\n", atoi(argv[1]));
} */