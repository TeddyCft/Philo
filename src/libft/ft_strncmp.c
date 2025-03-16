/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:17:17 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:33 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strcmp() function compares the first (at most) n bytes of s1 and s2.
The locale is not taken into account (for a locale-aware comparison, see
strcoll(3)). The comparison is done using unsigned characters. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] && str2[i])
	{
		if ((str1[i]) != (str2[i]))
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}

/* #include<string.h>
#include<stdio.h>
int	main()
{
	char s1[] = "1234", s2[] = "1235";
	int size = 3;
	printf("%d\n%d", ft_strncmp(s1,s2,size), strncmp(s1,s2,size));
} */
