/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:14:47 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:09 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL. */

#include "libft.h"

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

static int	split_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(char *)s != c && *(char *)s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		count = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	clear_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		i;

	i = 0;
	count = ft_count_word(s, c);
	str = 0;
	str = ft_calloc(count + 1, sizeof (char **));
	if (!(str))
		return (0);
	while (count > i)
	{
		while (*(char *)s == c)
			s++;
		str[i] = ft_strldup((char *)s, split_len(s, c));
		if (!(str[i]))
			return (clear_split(str), NULL);
		i++;
		s += split_len(s, c);
	}
	str[i] = 0;
	return (str);
}

/* int	main(void)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split("", '_');
	if (str[i] == 0)
		printf("%s\n", *str);
	while (str[i] != 0)
	{
		printf("%s\n", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
} */