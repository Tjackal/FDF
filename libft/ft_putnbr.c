/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:05:49 by tmarchen          #+#    #+#             */
/*   Updated: 2017/11/02 21:05:52 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	temp;
	long int	t;
	long int	size;

	size = 1;
	t = (long)n;
	if (n < 0)
	{
		ft_putchar('-');
		t = -t;
	}
	temp = t;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = t;
	while (size)
	{
		ft_putchar((char)((temp / size)) + '0');
		temp %= size;
		size /= 10;
	}
}
