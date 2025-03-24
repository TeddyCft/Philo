/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:35:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/03/24 15:39:12 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size * nmemb > 2147483647) || (SIZE_MAX / size <= nmemb))
		return (0);
	ptr = malloc(sizeof(char) * (size * nmemb));
	if (!(ptr))
		return (0);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}

/* void	ft_bzero(void *s, size_t n)
{
	while (s && (n-- > 0))
		*(char *)s++ = 0;
} */