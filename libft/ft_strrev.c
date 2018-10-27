/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 20:28:08 by tmarchen          #+#    #+#             */
/*   Updated: 2017/07/28 21:58:30 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		n;
	int		m;
	char	t;

	if (str == NULL)
		return (NULL);
	n = 0;
	while (str[n] != '\0')
		n++;
	m = -1;
	while (++m < --n)
	{
		t = str[m];
		str[m] = str[n];
		str[n] = t;
	}
	return (str);
}
