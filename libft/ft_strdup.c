/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 21:55:55 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/24 21:55:58 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)malloc(sizeof(*tmp) * (ft_strlen(s) + 1));
	if (tmp != NULL)
	{
		while (s[i])
		{
			tmp[i] = s[i];
			i++;
		}
		tmp[i] = s[i];
	}
	return (tmp);
}
