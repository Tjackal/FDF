/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:58:29 by tmarchen          #+#    #+#             */
/*   Updated: 2017/10/31 19:58:32 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s, char c, size_t *i)
{
	size_t j;

	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		j++;
		(*i)++;
	}
	return (j);
}

static void		ft_rm(char **tmp, int k)
{
	while (k >= 0)
		free(tmp[k--]);
	free(tmp);
}

static void		ft_shortcut(char const *s, char **tmp, size_t i, char c)
{
	size_t	j;
	int		l;
	int		k;

	l = 0;
	k = 0;
	while (s[i])
	{
		j = ft_len(s, c, &i);
		if (j)
		{
			tmp[k] = (char*)malloc(sizeof(char) * (j + 1));
			if (tmp[k] == NULL)
				return (ft_rm(tmp, k));
			while (j)
				tmp[k][l++] = s[i - j--];
			tmp[k++][l] = '\0';
			l = 0;
		}
		if (s[i] != '\0')
			i++;
	}
	tmp[k] = NULL;
}

static size_t	ft_sh(char const *s, char c, int i, size_t j)
{
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;

	if (s == NULL)
		return (NULL);
	tmp = (char**)malloc(sizeof(char*) * (ft_sh(s, c, 0, 0) + 1));
	if (tmp == NULL)
	{
		ft_rm(tmp, -1);
	}
	else
		ft_shortcut(s, tmp, 0, c);
	return (tmp);
}
