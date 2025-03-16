/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:58:23 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:58 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks for an alphabetic character; in the standard "C" locale, it is equivalent
to (isupper(c) || islower(c)).  In some locales, there may be additional
characters for which isalpha() is true—letters which are  neither  uppercase
nor lowercase.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
	printf("%d\n%d", isalpha(atoi(argv[1])), ft_isalpha(atoi(argv[1])));
}
*/