/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:02:31 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/31 17:02:45 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *tmp;
	char *t;

	if (s == NULL || f == NULL)
		return (NULL);
	tmp = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	t = tmp;
	if (tmp != NULL)
	{
		while (*s)
			*tmp++ = f(*s++);
		*tmp = '\0';
	}
	return (t);
}
