/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:53:26 by tmarchen          #+#    #+#             */
/*   Updated: 2017/07/29 16:27:02 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int r;

	r = 1;
	if (nb == 0)
		return (1);
	else if (nb > 12 || nb < 0)
		return (0);
	else
	{
		while (nb != 0)
		{
			r *= nb;
			nb--;
		}
		return (r);
	}
}
