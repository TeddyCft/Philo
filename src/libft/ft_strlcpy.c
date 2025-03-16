/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:41:42 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/20 13:45:08 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy a string. Copy src to string dst of size siz. At most siz-1 characters
will be copied. Always NULL terminates (unless siz == 0). */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i == 0 && size > 1)
	{
		dst[i] = src[i];
		return (ft_strlen((char *)src));
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}

/* int	main()
{
	char dst[10] = {'a','a','a','a','a','a','a','a','a','\0'};
	char src[] = "";
	char dst2[10] = {'a','a','a','a','a','a','a','a','a','\0'};
	char src2[] = "";
	size_t r1, r2;
	r1 = ft_strlcpy(dst, src, sizeof(dst));
	r2 = strlcpy(dst2, src2, sizeof(dst2));
	if(r1 == r2)
		printf("true");
	else
		printf("false");
	// printf("%ld\n", ft_strlcpy(dst, src, 20));
	// printf("dst = %s src = %s\n", dst, src);
	// printf("%ld\n", strlcpy(dst2, src2, 20));
	// printf("dst = %s src = %s\n", dst2, src2);
}   */
