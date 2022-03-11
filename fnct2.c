/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:29:44 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/04 13:42:15 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	ra(t_nbr *nbr)
{
	t_nbr	tmp;
	int		i;

	i = 0;
	tmp = nbr[0];
	while (tmp.size > ++i)
		nbr[i - 1] = nbr[i];
	nbr[0].size = tmp.size;
	nbr[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rb(t_nbr *nbr)
{
	t_nbr	tmp;
	int		i;

	i = 0;
	tmp = nbr[0];
	while (tmp.size > ++i)
		nbr[i - 1] = nbr[i];
	nbr[0].size = tmp.size;
	nbr[i - 1] = tmp;
	ft_printf("rb\n");
}

void	rr(t_nbr *nbr_a, t_nbr *nbr_b)
{
	t_nbr	tmp;
	int		i;

	i = 0;
	tmp = nbr_a[0];
	while (tmp.size > ++i)
		nbr_a[i - 1] = nbr_a[i];
	nbr_a[0].size = tmp.size;
	nbr_a[i - 1] = tmp;
	i = 0;
	tmp = nbr_b[0];
	while (tmp.size > ++i)
		nbr_b[i - 1] = nbr_b[i];
	nbr_b[0].size = tmp.size;
	nbr_b[i - 1] = tmp;
	ft_printf("rr\n");
}
