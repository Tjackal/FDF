/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:03:58 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/31 18:04:01 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;
	char *t;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) +
		ft_strlen((char*)s2) + 1));
	t = tmp;
	if (tmp != NULL)
	{
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = '\0';
		return (t);
	}
	return (NULL);
}
