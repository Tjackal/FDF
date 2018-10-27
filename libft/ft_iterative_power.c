/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 14:47:01 by tmarchen          #+#    #+#             */
/*   Updated: 2017/07/29 15:04:18 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int sum;

	sum = 1;
	if (power < 0)
		return (0);
	else if (power > 0)
	{
		while (power-- > 0)
		{
			sum *= nb;
		}
		return (sum);
	}
	else
		return (1);
}
