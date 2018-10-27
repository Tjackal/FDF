/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 06:16:48 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 06:16:50 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		quit(void *param)
{
	t_all *a;

	a = (t_all*)param;
	mlx_destroy_window((a->tdata)->mlx, (a->tdata)->window);
	clean(a);
	exit(1);
	return (0);
}

int		count_w(int *fd, char *argv)
{
	int		i;
	int		j;
	char	*c;

	j = 0;
	i = -1;
	*fd = open(argv, O_RDONLY);
	get_next_line(*fd, &c);
	while (c[++i])
	{
		if (((c[i] >= '0' && c[i] <= '9') || (c[i] >= 'a' && c[i] <= 'f') ||
			(c[i] >= 'A' && c[i] <= 'F'))
			&& (c[i + 1] == ' ' || c[i + 1] == '\t' || !(c[i + 1])))
			j++;
	}
	free(c);
	return (j);
}

void	set_field_stats(char *argv, t_field *field)
{
	int		fd;
	int		i;
	int		j;
	char	*c;

	j = count_w(&fd, argv);
	i = 1;
	while (get_next_line(fd, &c))
	{
		i++;
		free(c);
	}
	close(fd);
	field->h = i;
	field->w = j;
	field->dot = (t_dot**)malloc(sizeof(t_dot*) * i);
	while (--i >= 0)
		(field->dot)[i] = (t_dot*)malloc(sizeof(t_dot) * j);
}

int		main(int argc, char **argv)
{
	t_all all;

	if (argc == 2 && valid(argv[1]))
	{
		all.tdata = (t_data*)malloc(sizeof(t_data));
		all.tfield = (t_field*)malloc(sizeof(t_field));
		(all.tdata)->mlx = mlx_init();
		(all.tdata)->window = mlx_new_window((all.tdata)->mlx, WX, WY, "fdf");
		set_field_stats(argv[1], all.tfield);
		fill_field(argv[1], all.tfield);
		(all.tfield)->angle_x = 0;
		(all.tfield)->angle_y = 0;
		(all.tfield)->angle_z = 0;
		(all.tfield)->scale = 0;
		(all.tfield)->move_x = 0;
		(all.tfield)->move_y = 0;
		draw(all.tfield, all.tdata);
		mlx_hook((all.tdata)->window, 2, 5, key, &all);
		mlx_hook((all.tdata)->window, 17, 5, quit, &all);
		mlx_loop((all.tdata)->mlx);
	}
	else
		ft_putendl("usage: ./fdf <filename>");
	return (0);
}
