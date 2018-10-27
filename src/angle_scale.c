/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 06:25:19 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 06:37:01 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_dot	xangle(t_field *field, t_dot t)
{
	t_dot r;

	r.x = t.x;
	r.y = t.y * cos(field->angle_x * DEG) + t.z * sin(field->angle_x * DEG);
	r.z = -t.y * sin(field->angle_x * DEG) + t.z * cos(field->angle_x * DEG);
	return (r);
}

t_dot	yangle(t_field *field, t_dot t)
{
	t_dot r;

	r.x = t.x * cos(field->angle_y * DEG) + t.z * sin(field->angle_y * DEG);
	r.y = t.y;
	r.z = -t.x * sin(field->angle_y * DEG) + t.z * cos(field->angle_y * DEG);
	return (r);
}

t_dot	zangle(t_field *field, t_dot t)
{
	t_dot r;

	r.x = t.x * cos(field->angle_z * DEG) - t.y * sin(field->angle_z * DEG);
	r.y = t.x * sin(field->angle_z * DEG) + t.y * cos(field->angle_z * DEG);
	r.z = t.z;
	return (r);
}

t_dot	scale(t_dot t, int scale)
{
	t_dot r;

	r = t;
	if (scale > 0)
	{
		r.x *= scale;
		r.y *= scale;
		r.z *= scale;
	}
	else
	{
		r.x /= abs(scale);
		r.y /= abs(scale);
		r.z /= abs(scale);
	}
	return (r);
}

t_dot	angle_scale(t_field *field, t_dot t)
{
	t_dot r;

	if (field->scale)
		r = scale(t, field->scale);
	else
		r = t;
	r = xangle(field, r);
	r = yangle(field, r);
	r = zangle(field, r);
	if (field->move_x)
		r.x += field->move_x;
	if (field->move_y)
		r.y += field->move_y;
	r.z = t.z;
	r.color = t.color;
	return (r);
}
