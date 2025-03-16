/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:41:07 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:18:18 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memcmp() function compares the first n bytes (each interpreted as
unsigned char) of the memory areas s1 and s2. */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	i;

	i = 0;
	while ((size_t)i < n)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char s1[] = "test", s2[] = "test";
	size_t n = 5;
	printf("%d\n%d", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
*/