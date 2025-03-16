/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:41:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:21 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alloue (avec malloc(3)) et retourne une nouvelle
chaîne, résultat de la concaténation de s1 et s2. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		l1;
	int		l2;

	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	i = 0;
	str = 0;
	str = ft_calloc(l1 + l2 + 1, 1);
	if (!(str))
		return (0);
	while (i < l1)
	{
		str[i] = *(char *)s1++;
		i++;
	}
	while (i < l1 + l2)
	{
		str[i] = *(char *)s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int	main()
{
	char *ptr = 0;
	ptr = ft_strjoin("croissant", " is good");
	printf("%s", ptr);
	free(ptr);
} */
