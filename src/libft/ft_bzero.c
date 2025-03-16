/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:15:19 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:53 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The bzero() function erases the data in the n bytes of the memory starting
at the location pointed to by s, by writing zeros (bytes containing '\0') to
that area. */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int main()
{
    void *ptr1 = 0; 
    void *ptr2 = 0;
    ptr1 = malloc(sizeof(void) * 5);
    if (ptr1 == 0)
        return (0);
    ptr2 = malloc(sizeof(void) * 5);
    if (ptr2 == 0)
        return (0);
    char *str1 = ptr1;
    char *str2 = ptr2;
    ft_bzero(str1, 5);
    bzero(str2, 5);
    printf("%d\n%d", *(int *)str1, *(int *)str2);
    free(ptr1);
    free(ptr2);
    return(0);    
}*/