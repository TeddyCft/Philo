/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:31:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:18:02 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks for a digit (0 through 9). */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n%d", isdigit(atoi(argv[1])), ft_isdigit(atoi(argv[1])));
}
*/