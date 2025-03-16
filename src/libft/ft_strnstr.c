/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:12:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:35 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strnstr() function locates the first occurrence of the null-terminated
string little in the string big, where not more than len characters are
searched. Characters that appear after a ‘\0’ character are not searched. */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
		{
			j++;
		}
		if ((i + j) <= len && little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

/* #include<stdio.h>
#include<bsd/string.h>
int	main()
{
	char big[] = "aaabcabcd", little[] = "abcd";
	size_t len = 9;
	printf("%s\n%s", ft_strnstr(big, little, len), strnstr(big, little, len));
} */
