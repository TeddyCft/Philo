/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:37:15 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:13 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  strchr() function returns a pointer to the first occurrence of the
character c in the string s. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c % 256)
		{
			s = s + i;
			return ((char *)s);
		}
		i++;
	}
	if (s[i] == c % 256)
	{
		s = s + i;
		return ((char *)s);
	}
	return (0);
}

/* #include<stdio.h>
#include<string.h>
int	main()
{
	int c = 's';
	printf("%s\n%s", ft_strchr("test",c), strchr("test",c));
} */
