/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:43:07 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/27 19:43:10 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tt;

	tt = (unsigned char*)s;
	while (n--)
	{
		if (*tt++ == (unsigned char)c)
			return (--tt);
	}
	return (NULL);
}
