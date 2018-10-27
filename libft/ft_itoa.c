/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:18:46 by tmarchen          #+#    #+#             */
/*   Updated: 2017/11/02 19:18:48 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_things(char *c, unsigned int temp, int size)
{
	unsigned int t;

	t = temp;
	if (*c == '-')
		c++;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = t;
	while (size)
	{
		*c++ = ((char)((temp / (unsigned int)size)) + '0');
		temp %= (unsigned int)size;
		size /= 10;
	}
	*c = '\0';
}

char		*ft_itoa(int n)
{
	unsigned int	temp;
	unsigned int	ln;
	int				size;
	int				m;
	char			*c;

	m = 0;
	size = 1;
	if (n < 0)
	{
		m = 1;
		ln = -(unsigned int)n;
		size++;
	}
	else
		ln = (unsigned int)n;
	temp = ln;
	while (temp /= 10)
		size++;
	if (!(c = ft_strnew((size_t)size)))
		return (NULL);
	if (m == 1)
		*c = '-';
	ft_things(c, ln, 1);
	return (c);
}
