/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:34:45 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/04 13:34:45 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_nbr *nbr)
{
	int		i;
	t_nbr	tmp;

	i = nbr[0].size - 1;
	tmp = nbr[i];
	tmp.size = nbr[0].size;
	while (i > 0)
	{
		nbr[i] = nbr[i - 1];
		i--;
	}
	nbr[0] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_nbr *nbr)
{
	int		i;
	t_nbr	tmp;

	i = nbr[0].size - 1;
	tmp = nbr[i];
	tmp.size = nbr[0].size;
	while (i-- > 0)
	{
		nbr[i] = nbr[i - 1];
		i--;
	}
	nbr[0] = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_nbr *nbr_a, t_nbr *nbr_b)
{
	int		i;
	t_nbr	tmp;

	i = nbr_a[0].size - 1;
	tmp = nbr_a[i];
	tmp.size = nbr_a[0].size;
	while (i-- > 0)
	{
		nbr_a[i] = nbr_a[i - 1];
		i--;
	}
	nbr_a[0] = tmp;
	i = nbr_b[0].size - 1;
	tmp = nbr_b[i];
	tmp.size = nbr_b[0].size;
	while (i-- > 0)
	{
		nbr_b[i] = nbr_b[i - 1];
		i--;
	}
	nbr_b[0] = tmp;
	ft_printf("rrr\n");
}
