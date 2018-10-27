/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:14:11 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/27 17:14:14 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			cc;
	unsigned char			*t;
	const unsigned char		*tt;

	cc = (unsigned char)c;
	t = dst;
	tt = src;
	while (n--)
	{
		*t = *tt++;
		if (*t++ == cc)
			return (t);
	}
	return (NULL);
}
