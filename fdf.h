/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:51:32 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 01:52:12 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define WX 1400
# define WY 1000
# define SPC 40

# define DEG M_PI / 180

typedef struct			s_data
{
	void *mlx;
	void *window;
}						t_data;

typedef struct			s_dot
{
	int x;
	int y;
	int z;
	int color;
}						t_dot;

typedef struct			s_field
{
	int		w;
	int		h;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	int		scale;
	int		move_x;
	int		move_y;
	t_dot	**dot;
}						t_field;

typedef struct			s_all
{
	t_data		*tdata;
	t_field		*tfield;
}						t_all;

typedef	struct			s_params
{
	int stp;
	int dx;
	int dy;
	int err;
	int y_step;
	int m;
	int ff;
}						t_params;

void					swap_xy(int *x, int *y);

void					line(t_dot t0, t_dot t1, t_data *data);

t_dot					angle_scale(t_field *field, t_dot t);

void					draw(t_field *field, t_data *data);

void					clean(t_all *all);

int						key(int button, void *param);

void					fill_field(char *argv, t_field *field);

int						valid(char *argv);

#endif
