/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:25 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:16:50 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memchr() function scans the initial n bytes of the memory area pointed to
by s for the first instance of c. Both c and the bytes of the memory area
pointed to by s are interpreted as unsigned char. 
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char) c)
			return ((void *)s);
		s++;
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char str[] = "test";
	int c = 't';
	size_t n = 4;
	
	printf("%s\n%s", (char *)ft_memchr(str,c,n), (char *)memchr(str,c,n));
}
*/