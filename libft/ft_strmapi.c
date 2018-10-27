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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	char			*t;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	tmp = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	t = tmp;
	if (tmp != NULL)
	{
		while (*s)
			*tmp++ = f(i++, *s++);
		*tmp = '\0';
	}
	return (t);
}
