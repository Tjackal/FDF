/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:24:59 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/30 18:25:02 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *tmp;
	void *t;

	tmp = (void*)malloc(sizeof(void*) * size);
	t = tmp;
	if (tmp != NULL)
	{
		while (size--)
			*(char*)tmp++ = 0;
		return (t);
	}
	return (NULL);
}
