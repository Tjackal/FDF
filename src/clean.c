/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 06:39:31 by tmarchen          #+#    #+#             */
/*   Updated: 2018/03/05 06:39:33 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	clean(t_all *all)
{
	int k;

	k = -1;
	while (++k < (all->tfield)->h)
		free(((all->tfield)->dot)[k]);
	free((all->tfield)->dot);
	free(all->tfield);
	free(all->tdata);
}
