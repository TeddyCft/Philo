/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:00:14 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:55:34 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applique la fonction ’f’ à chaque caractère de
la chaîne de caractères ’s’, passant son index
comme premier argument et le caractère lui-même
comme second argument. Une nouvelle chaîne de
caractères est créée (avec malloc(3)), résultant
des applications successives de ’f’. */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	ptr = ft_calloc(ft_strlen((char *)s) + 1, 1);
	if (!(ptr))
		return (0);
	if (!(f))
		return ((char *)s);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}

/* char	posnum(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char *test;
	
	test = 0;
	test = ft_strmapi("00000", &posnum);
	printf("%s", test);
	free(test);
} */