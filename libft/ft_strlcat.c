/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:33:14 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/28 17:33:18 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstl;
	size_t srcl;
	size_t possibl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen((char*)src);
	possibl = dstsize - dstl - 1;
	if (dstsize <= dstl)
		return (srcl + dstsize);
	if (((dstsize - dstl - 1) > 0) && *src)
	{
		dst += dstl;
		while (possibl-- && *src != '\0')
			*dst++ = *src++;
		*dst = '\0';
	}
	return (dstl + srcl);
}
