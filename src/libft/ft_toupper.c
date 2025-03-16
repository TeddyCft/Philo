/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:20:46 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:16:31 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
If c is a lowercase letter, toupper() returns its uppercase equivalent, if an
uppercase representation exists in the current locale.  Otherwise, it returns
c.  The toupper_l() function performs the same task, but uses the locale
referred to by the locale handle locale.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include<ctype.h>
#include<stdio.h>
int main()
{
    int test = 'c';
    printf("%c\n%c", (char)ft_toupper(test), (char)toupper(test));
    return(0);
}
*/