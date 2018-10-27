/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:02:34 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/28 19:02:38 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *cc;

	cc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			cc = (char*)s;
		s++;
	}
	if (*s == (char)c)
		cc = (char*)s;
	return (cc);
}
