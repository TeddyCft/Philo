/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:05:16 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:17:18 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères transmise comme argument,
et en passant son index comme premier argument.
Chaque caractère est transmis par adresse à ’f’
afin d’être modifié si nécessaire. */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!(f))
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	posnum(unsigned int i, char *c)
{
	c[0] = c[0] + i ;
	return;
}

int	main(void)
{
	char test[] = "00000";
	ft_striteri(test, &posnum);
	printf("%s", test);
} */