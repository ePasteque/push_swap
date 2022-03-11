/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:44:08 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/08 15:51:10 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_nbr *nbr)
{
	t_nbr	tmp;

	if (nbr[0].size > 1)
	{
		tmp = nbr[0];
		nbr[0] = nbr[1];
		nbr[1] = tmp;
		nbr[0].size = nbr[1].size;
		ft_printf("sa\n");
	}
}

void	sb(t_nbr *nbr)
{
	t_nbr	tmp;

	if (nbr[0].size > 1)
	{
		tmp = nbr[0];
		nbr[0] = nbr[1];
		nbr[1] = tmp;
		nbr[0].size = nbr[1].size;
		ft_printf("sa\n");
	}
}

void	ss(t_nbr *nbr_a, t_nbr *nbr_b)
{
	t_nbr	tmp;

	if (nbr_a[0].size > 1 && nbr_b[0].size > 1)
	{
		tmp = nbr_a[0];
		nbr_a[0] = nbr_a[1];
		nbr_a[1] = tmp;
		nbr_a[0].size = nbr_a[1].size;
		tmp = nbr_b[0];
		nbr_b[0] = nbr_b[1];
		nbr_b[1] = tmp;
		nbr_b[0].size = nbr_b[1].size;
		ft_printf("ss\n");
	}
}

void	pa(t_nbr *nbr_a, t_nbr *nbr_b)
{
	int	i;
	int	size_a;
	int	size_b;

	if (nbr_b[0].size != 0)
	{
		size_b = nbr_b[0].size;
		size_a = nbr_a[0].size;
		i = nbr_a[0].size;
		while (--i != -1)
			nbr_a[i + 1] = nbr_a[i];
		nbr_a[0] = nbr_b[0];
		i = 0;
		while (size_b > ++i)
			nbr_b[i - 1] = nbr_b[i];
		nbr_a[0].size = size_a + 1;
		nbr_b[0].size = size_b - 1;
		ft_printf("pa\n");
	}
}

void	pb(t_nbr *nbr_a, t_nbr *nbr_b)
{
	int		i;
	int		size_a;
	int		size_b;

	if (nbr_a[0].size != 0)
	{
		size_a = nbr_a[0].size;
		size_b = nbr_b[0].size;
		i = nbr_b[0].size;
		while (--i > -1)
			nbr_b[i + 1] = nbr_b[i];
		nbr_b[0] = nbr_a[0];
		i = 0;
		while (size_a > ++i)
			nbr_a[i - 1] = nbr_a[i];
		nbr_a[0].size = size_a - 1;
		nbr_b[0].size = size_b + 1;
		ft_printf("pb\n");
	}
}
