/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:07:53 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/02/07 12:10:02 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns absolute value of int i, if i is int min returns i
int	ft_abs(int i)
{
	if (i < 0 && i > -2147483648)
		return (-i);
	else
		return (i);
}
