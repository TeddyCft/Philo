/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:00:08 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:19:13 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memset() function fills the first n bytes of the memory area pointed to
by s with the constant byte c. */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	if (!(s))
		*(int *)s = 1;
	while (s && (n-- > 0))
	{
		*(char *)s++ = c;
		i++;
	}
	return (s - i);
}

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    void *ptr1 = 0; 
    void *ptr2 = 0;
    int c = 42;
    ptr1 = malloc(sizeof(void) * 5);
    if (ptr1 == 0)
        return (0);
    ptr2 = malloc(sizeof(void) * 5);
    if (ptr2 == 0)
        return (0);
    char *str1 = ptr1;
    char *str2 = ptr2;
    ft_memset(str1, c, 5);
    memset(str2, c, 5);
    printf("%s\n%s", str1, str2);
    free(ptr1);
    free(ptr2);
    return(0);    
}
*/