/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:14:36 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/12/09 11:26:43 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’. */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (len > (size_t)ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	str = 0;
	if (start > (unsigned int)ft_strlen((char *)s))
		return (ft_calloc(1, 1));
	str = ft_calloc(len + 1, 1);
	if (!(str))
		return (0);
	while (start-- >= 1)
		s++;
	while (((size_t)i < len) && (*(char *)s != '\0'))
	{
		str[i] = *(char *)s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int	main(void)
{
	char	*str = 0;
	

	str = ft_substr("tripouille", 0, 42000);
	printf("%s", str);
	free(str);
} */
