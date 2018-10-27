/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:23:10 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/30 19:23:14 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;
	char *t;

	tmp = (char*)malloc(sizeof(char) * (size + 1));
	t = tmp;
	if (tmp != NULL)
	{
		while (1 + size--)
			*tmp++ = '\0';
		return (t);
	}
	return (NULL);
}
