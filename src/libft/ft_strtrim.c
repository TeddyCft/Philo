/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:24:38 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/12/13 15:27:35 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alloue (avec malloc(3)) et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères. */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	while (*(char *)set != '\0')
	{
		if (c == *(char *)set++)
			return (1);
	}
	return (0);
}

static int	trim_len(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	start;

	i = ft_strlen(s1) - 1;
	end = ft_strlen(s1);
	start = 0;
	while (s1[i] && ((is_set(s1[i], set)) && i > 0))
	{
		end--;
		i--;
	}
	i = 0;
	while (s1[i] && (is_set(s1[i], set)))
	{
		start++;
		i++;
	}
	return (end - start);
}

/* static char	*ft_strldup(const char *src, int l)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	str = ft_calloc(l + 1, 1);
	if (str == 0)
		return (NULL);
	while (l > i && (src[i]))
	{
		str[i] = src[i];
		i++;
	}
	return (str);
} */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		l;

	str = 0;
	l = trim_len(s1, set);
	if (!(set) || l <= 0)
	{
		if (!(set))
			str = ft_strldup(s1, ft_strlen(s1));
		else if (l <= 0)
			str = ft_strldup("", 0);
		if (!(str))
			return (0);
		return (str);
	}
	while (is_set(*(char *)s1, set))
		s1++;
	str = ft_strldup((char *)s1, l);
	if (!(str))
		return (0);
	return (str);
}

/* int	main(void)
{
	printf("%s", ft_strtrim("BBBBBbanana", "BA"));
} */
