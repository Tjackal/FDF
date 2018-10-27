/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:43:17 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/27 18:43:22 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*t;
	const unsigned char		*tt;
	size_t					i;

	i = n;
	t = dst;
	tt = src;
	if (src < dst)
	{
		t += (n - 1);
		tt += (n - 1);
		while (n--)
			*t-- = *tt--;
	}
	else
		while (n--)
			*t++ = *tt++;
	return (dst);
}
