/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:33:51 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:23 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Concatenate two strings. Appends src to string dst of size siz
(unlike strncat(), siz is the full size of dst, not space left).
At most siz-1 characters will be copied. Always NULL terminates
(unless siz <= strlen(dst)). */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (j > size || (j == 0 && size == 0))
		return (size + ft_strlen((char *)src));
	while ((i + j < size - 1) && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (size < j)
		return (size + ft_strlen((char *)src));
	else
		return (j + ft_strlen((char *)src));
}

/* int	main()
{
	int	size = 0;
	char dest1[30]; memset(dest1, 0, 30);
	printf("FT : returns : %zu dst = %s\n",
	ft_strlcat(dest1,"123", size), dest1);
	char dest2[30]; memset(dest2, 0, 30);
	printf("FT : returns : %zu dst = %s\n",
	strlcat(dest2,"123", size), dest2);
} */

/* #include<stdio.h>
#include<bsd/string.h>
int	main()
{
	int size = 6;
	char dst1[30]; memset(dst1, 0, 30);
	char src1[] = "AAAAAAAAA";
	char dst2[30]; memset(dst2, 0, 30);
	char src2[] = "AAAAAAAAA";
	memset(dst1, 'B', 4);
	memset(dst2, 'B', 4);
	printf("FT : returns : %zu dst = %s src = %s\n", \
	ft_strlcat(dst1,src1, size), dst1, src1);
	printf("OG : returns : %zu dst = %s src = %s\n",\
	strlcat(dst2,src2, size),dst2, src2);
} */
