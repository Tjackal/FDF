/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:18:29 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/27 20:18:32 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if ((*(unsigned char*)s1++ - *(unsigned char*)s2++) != 0)
			return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
	return (0);
}
