/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:51:44 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/31 17:51:49 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *tmp;
	char *t;

	if (s == NULL)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	t = tmp;
	s += start;
	if (tmp != NULL)
	{
		while (len--)
			*tmp++ = *s++;
		*tmp = '\0';
		return (t);
	}
	return (NULL);
}
