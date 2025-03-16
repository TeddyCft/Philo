/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:36:22 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:19:17 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The memcmp() function compares the first n bytes (each interpreted as
unsigned char) of the memory areas s1 and s2. */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (dest == 0)
		*(int *)dest = 1;
	while (dest && n-- > 0)
	{
		*(char *)dest++ = *(char *)src++;
		i++;
	}
	return (dest - i);
}

/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    void *dst1 = 0, *dst2 = 0;
    //const void *src1, *src2;
    char str1[] = "test";
    
    dst1 = malloc(sizeof(char) * 5);
    if (dst1 == 0)
        return(0);
    dst2 = malloc(sizeof(char) * 5);
    if (dst2 == 0)
        return(0);
    printf("%s\n%s", (char *)ft_memcpy(dst1, str1, 5),\
	(char *)memcpy(dst2, str1, 5));
    free(dst1);
    free(dst2);
    return(0);
} */