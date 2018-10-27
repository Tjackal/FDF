/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 06:19:43 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 06:19:46 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		atoi_hex(char *str)
{
	int i;
	int n;

	n = 0;
	i = 1;
	while (++i < 10)
	{
		n *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			n += str[i] - '0';
		else if ((str[i] >= 'A' && str[i] <= 'F'))
			n += str[i] - '7';
		else if ((str[i] >= 'a' && str[i] <= 'f'))
			n += str[i] - 'W';
		else
		{
			n /= 16;
			break ;
		}
	}
	return (n);
}

void	set_z_color(char *c, t_dot *dot, int *t)
{
	int i;

	i = *t;
	dot->z = ft_atoi(&(c[i]));
	while (c[i + 1] && ((c[i] >= '0' && c[i] <= '9') || c[i] == '-'))
		i++;
	if (c[i] == ',' && c[i + 1])
	{
		dot->color = atoi_hex(&(c[i + 1]));
		while (c[i + 1] && c[i] != ' ' && c[i] != '\n')
			i++;
	}
	else if (dot->z >= 10)
		dot->color = 0x00FF0000;
	else if (dot->z <= -10)
		dot->color = 0x000000FF;
	else
		dot->color = 0x00FFFFFF;
	*t = i;
}

void	fill_field(char *argv, t_field *field)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	char	*c;

	fd = open(argv, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &c) && j < field->h)
	{
		i = -1;
		k = 0;
		while (c[++i])
		{
			if ((c[i] >= '0' && c[i] <= '9') || c[i] == '-')
			{
				((field->dot)[j][k]).x = k * SPC - (SPC * (field->w - 1) / 2);
				((field->dot)[j][k]).y = j * SPC - (SPC * (field->h - 1) / 2);
				set_z_color(c, &((field->dot)[j][k++]), &i);
			}
		}
		j++;
		free(c);
	}
	close(fd);
}
