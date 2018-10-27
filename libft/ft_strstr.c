/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:40:22 by tmarchen          #+#    #+#             */
/*   Updated: 2017/07/31 23:24:39 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t needlel;

	needlel = ft_strlen((char*)needle);
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		if (ft_strncmp((char*)haystack, (char*)needle, needlel) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
