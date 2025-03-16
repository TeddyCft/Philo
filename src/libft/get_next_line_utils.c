/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:54:38 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/16 14:17:19 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*gnl_ft_strchr(const char *s, int c)
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

char	*gnl_ft_strjoin(char const *s1, char const *s2)
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

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
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
