/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:40:48 by tmarchen          #+#    #+#             */
/*   Updated: 2018/01/07 16:40:50 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		set_rgb(int *rgb, int l, int *clr)
{
	if (!l)
		return (1);
	clr[0] = clr[1];
	if (clr[1] != clr[2])
	{
		if ((clr[1] & 0x00FF0000) > (clr[2] & 0x00FF0000))
			*rgb = (((clr[1] & 0xFF0000) - (clr[2] & 0xFF0000)) / l) & 0xFF0000;
		else
			*rgb = (((clr[2] & 0xFF0000) - (clr[1] & 0xFF0000)) / l) & 0xFF0000;
		if ((clr[1] & 0x0000FF00) > (clr[2] & 0x0000FF00))
			rgb[1] = (((clr[1] & 0xFF00) - (clr[2] & 0xFF00)) / l) & 0xFF00;
		else
			rgb[1] = (((clr[2] & 0xFF00) - (clr[1] & 0xFF00)) / l) & 0xFF00;
		if ((clr[1] & 0x000000FF) > (clr[2] & 0x000000FF))
			rgb[2] = (((clr[1] & 0xFF) - (clr[2] & 0xFF)) / l) & 0xFF;
		else
			rgb[2] = (((clr[2] & 0xFF) - (clr[1] & 0xFF)) / l) & 0xFF;
		if ((clr[1] & 0x00FF0000) > (clr[2] & 0x00FF0000))
			rgb[0] = -rgb[0];
		if ((clr[1] & 0x0000FF00) > (clr[2] & 0x0000FF00))
			rgb[1] = -rgb[1];
		if ((clr[1] & 0x000000FF) > (clr[2] & 0x000000FF))
			rgb[2] = -rgb[2];
	}
	return (0);
}

void	preliminaries(t_dot *t0, t_dot *t1, t_params *p)
{
	p->m = 1;
	if (t0->y > t1->y || t0->x > t1->x)
		p->m = -1;
	if (t0->y > t1->y && t0->x > t1->x)
		p->m = 1;
	p->ff = abs(t1->y - t0->y) == abs(t1->x - t0->x);
	p->stp = abs(t1->y - t0->y) > abs(t1->x - t0->x);
	if (p->stp)
	{
		swap_xy(&(t0->x), &(t0->y));
		swap_xy(&(t1->x), &(t1->y));
	}
	if (t0->x > t1->x)
	{
		swap_xy(&(t0->x), &(t1->x));
		swap_xy(&(t0->y), &(t1->y));
		swap_xy(&(t0->color), &(t1->color));
	}
	p->dx = t1->x - t0->x;
	p->dy = abs(t1->y - t0->y);
	p->err = p->dx / 2;
	p->y_step = (t0->y < t1->y) ? 1 : -1;
}

#define IX(x, y) p->stp ? ((x) + WX / 2) : ((y) + WX / 2)
#define IY(x, y) p->stp ? ((x) + WY / 2) : ((y) + WY / 2)
#define PUT(x, y, c) mlx_pixel_put(data->mlx, data->window, (x), (y), (c))

void	fourty_five(t_data *data, t_params *p, t_dot *t0, int clr)
{
	if (p->ff)
	{
		PUT(IX(t0->y - p->m, t0->x), IY(t0->x, t0->y - p->m), clr);
		PUT(IX(t0->y + p->m, t0->x), IY(t0->x, t0->y + p->m), clr);
	}
}

void	pixel_put(t_data *data, t_params *p, t_dot *t0, int *clr)
{
	if (p->err != (p->dx / 2))
	{
		if (p->err > (p->dx / 2))
		{
			clr[3] = clr[0] + ((((p->dx / 2) - p->err) *
			((0xFF000000 / (p->dx - (p->dx / 10))) & 0xFF000000)) & 0xFF000000);
			PUT(IX(t0->y - p->m, t0->x), IY(t0->x, t0->y - p->m), clr[3]);
		}
		else if (p->err < (p->dx / 2))
		{
			clr[3] = clr[0] + (((p->err - (p->dx / 2)) *
			((0xFF000000 / (p->dx - (p->dx / 10))) & 0xFF000000)) & 0xFF000000);
			PUT(IX(t0->y + p->m, t0->x), IY(t0->x, t0->y + p->m), clr[3]);
		}
		clr[3] = clr[0] + ((0xFF000000 - (clr[3] & 0xFF000000)) & 0xFF000000);
		PUT(IX(t0->y, t0->x), IY(t0->x, t0->y), clr[3]);
	}
	else
	{
		PUT(IX(t0->y, t0->x), IY(t0->x, t0->y), clr[0]);
		fourty_five(data, p, t0, clr[0] + 0xa0000000);
	}
}

void	line(t_dot t0, t_dot t1, t_data *data)
{
	t_params	p;
	int			rgb[3];
	int			clr[4];

	preliminaries(&t0, &t1, &p);
	clr[1] = t0.color;
	clr[2] = t1.color;
	if (set_rgb(rgb, sqrt(pow(t1.x - t0.x, 2) + pow(t1.y - t0.y, 2)), clr))
		return ;
	while (t0.x <= t1.x)
	{
		if (!(abs((p.stp ? t0.y : t0.x)) > (WX / 2)
			|| abs((p.stp ? t0.x : t0.y)) > (WY / 2)))
			pixel_put(data, &p, &t0, clr);
		if (clr[1] != clr[2])
			clr[0] += rgb[0] + rgb[1] + rgb[2];
		p.err -= p.dy;
		if (p.err < 0)
		{
			t0.y += p.y_step;
			p.err += p.dx;
		}
		t0.x++;
	}
}
