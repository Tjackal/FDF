/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:34:22 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/12 19:34:24 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		check(int i, char *c, int *j)
{
	int r;

	r = 0;
	if (!((c[i] >= 'a' && c[i] <= 'f') || (c[i] >= 'A' && c[i] <= 'F')
	|| (c[i] >= '0' && c[i] <= '9') || c[i] == ' ' || c[i] == '\t'
	|| c[i] == '\n' || c[i] == ',' || c[i] == 'x' || c[i] == 'X'
	|| c[i] == '-'))
		return (1);
	if (((c[i] >= '0' && c[i] <= '9') || (c[i] >= 'a' && c[i] <= 'f') ||
	(c[i] >= 'A' && c[i] <= 'F'))
	&& (c[i + 1] == ' ' || c[i + 1] == '\t' || !(c[i + 1])))
		(*j)++;
	if ((c[i] >= 'a' && c[i] <= 'f') || (c[i] >= 'A' && c[i] <= 'F'))
	{
		while (--i >= 0 && c[i] != ' ' && c[i] != '\t')
		{
			if ((c[i] == 'x' || c[i] == 'X') && (i - 3) >= 0 && c[i - 1] == '0'
				&& c[i - 2] == ',' && c[i - 3] >= '0' && c[i - 3] <= '9')
				r = 1;
		}
		if (!r)
			return (1);
	}
	return (0);
}

int		valid(char *argv)
{
	int		i;
	int		j;
	int		prj;
	int		fd;
	char	*c;

	prj = -1;
	fd = open(argv, O_RDONLY);
	while ((j = get_next_line(fd, &c)))
	{
		if (j < 0)
			return (0);
		j = 0;
		i = -1;
		while (c[++i])
			if (check(i, c, &j))
				return (0);
		if (prj >= 0 && j != prj)
			return (0);
		prj = j;
		free(c);
	}
	close(fd);
	return (1);
}
