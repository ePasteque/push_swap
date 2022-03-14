/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:38:48 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/14 10:27:07 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_3(t_nbr *nbr_a, int argc, t_nbr *nbr_b)
{
	if (is_sort(nbr_a, argc, nbr_b, 1) == 0)
		return ;
	if (nbr_a[0].index < nbr_a[1].index && nbr_a[2].index > nbr_a[0].index)
	{
		sa(nbr_a);
		ra(nbr_a);
	}
	else if (nbr_a[0].index > nbr_a[1].index && nbr_a[1].index > nbr_a[2].index)
	{
		sa(nbr_a);
		rra(nbr_a);
	}
	else if (nbr_a[0].index > nbr_a[1].index && nbr_a[0].index < nbr_a[2].index)
		sa(nbr_a);
	else if (nbr_a[0].index < nbr_a[1].index && nbr_a[2].index < nbr_a[0].index)
		rra(nbr_a);
	else if (nbr_a[0].index > nbr_a[2].index && nbr_a[1].index < nbr_a[2].index)
		ra(nbr_a);
}

static int	find(t_nbr *nbr_a, int index)
{
	int	i;

	i = -1;
	while (nbr_a[++i].index != index)
		;
	return (i);
}

static void	is_5(t_nbr *nbr_a, t_nbr *nbr_b, int argc)
{
	int	j;
	int	time;

	time = -1;
	while (++time < 2)
	{
		j = find(nbr_a, time);
		while (nbr_a[0].index != time)
		{
			if (j >= 2)
				rra(nbr_a);
			else
				ra(nbr_a);
		}
		pb(nbr_a, nbr_b);
	}
	is_3(nbr_a, argc, nbr_b);
	pa(nbr_a, nbr_b);
	pa(nbr_a, nbr_b);
}

static void	specific_case(t_nbr *nbr_a, t_nbr *nbr_b, int argc)
{
	if (argc == 3)
	{
		sa(nbr_a);
		quit(nbr_a, nbr_b);
	}
	else if (argc == 4)
		is_3(nbr_a, argc, nbr_b);
	else if (argc == 6)
		is_5(nbr_a, nbr_b, argc);
	quit(nbr_a, nbr_b);
}

void	radix(t_nbr *nbr_a, t_nbr *nbr_b, int argc)
{
	int		i;
	int		n;
	int		size;

	n = 1;
	if (argc < 5 || argc == 6)
		specific_case(nbr_a, nbr_b, argc);
	while (is_sort(nbr_a, argc, nbr_b, 1) != 0)
	{
		i = -1;
		size = nbr_a[0].size;
		while (size > ++i)
		{
			if (n & ~nbr_a[0].index)
				pb(nbr_a, nbr_b);
			else
				ra(nbr_a);
		}
		i = -1;
		size = nbr_b[0].size;
		while (size > ++i)
			pa(nbr_a, nbr_b);
		n *= 2;
	}
}
