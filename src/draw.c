/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 06:54:25 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 06:54:27 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw(t_field *field, t_data *data)
{
	int		i;
	int		j;
	t_dot	t;
	t_dot	t1;

	i = -1;
	while (++i < field->h)
	{
		j = -1;
		while (++j < field->w)
		{
			t = angle_scale(field, (field->dot)[i][j]);
			if (j != field->w - 1)
			{
				t1 = angle_scale(field, (field->dot)[i][j + 1]);
				line(t, t1, data);
			}
			if (i != field->h - 1)
			{
				t1 = angle_scale(field, (field->dot)[i + 1][j]);
				line(t, t1, data);
			}
		}
	}
}
