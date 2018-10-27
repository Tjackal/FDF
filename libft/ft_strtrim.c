/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:56:15 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/31 18:56:17 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	unsigned int	j;
	char			*res;

	if (s == NULL)
		return (NULL);
	i = ft_strlen((char*)s);
	j = 0;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	i -= j;
	res = ft_strsub(s, j, i);
	if (res == NULL)
	{
		res = (char*)malloc(sizeof(char));
		if (res != NULL)
			*res = '\0';
	}
	return (res);
}
