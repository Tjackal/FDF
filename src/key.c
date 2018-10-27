/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 06:39:45 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 06:43:28 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	additional_key(int button, t_all *a)
{
	if (button == 43)
		(a->tfield)->angle_z = ((a->tfield)->angle_z - 5) % 360;
	else if (button == 47)
		(a->tfield)->angle_z = ((a->tfield)->angle_z + 5) % 360;
	else if (button == 69)
		(a->tfield)->scale += 2;
	else if (button == 78)
		(a->tfield)->scale -= 2;
	else if (button == 88)
		(a->tfield)->move_x += 10;
	else if (button == 86)
		(a->tfield)->move_x -= 10;
	else if (button == 91)
		(a->tfield)->move_y -= 10;
	else if (button == 84)
		(a->tfield)->move_y += 10;
	else
		return ;
	mlx_clear_window((a->tdata)->mlx, (a->tdata)->window);
	draw(a->tfield, a->tdata);
}

int		key(int button, void *param)
{
	t_all *a;

	a = (t_all*)param;
	if (button == 53)
	{
		mlx_destroy_window((a->tdata)->mlx, (a->tdata)->window);
		clean(a);
		exit(1);
	}
	else if (button == 123)
		(a->tfield)->angle_y = ((a->tfield)->angle_y - 5) % 360;
	else if (button == 124)
		(a->tfield)->angle_y = ((a->tfield)->angle_y + 5) % 360;
	else if (button == 126)
		(a->tfield)->angle_x = ((a->tfield)->angle_x - 5) % 360;
	else if (button == 125)
		(a->tfield)->angle_x = ((a->tfield)->angle_x + 5) % 360;
	else
	{
		additional_key(button, a);
		return (1);
	}
	mlx_clear_window((a->tdata)->mlx, (a->tdata)->window);
	draw(a->tfield, a->tdata);
	return (0);
}
