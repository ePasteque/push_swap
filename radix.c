/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:38:48 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/11 11:22:00 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_3(t_nbr *nbr_a)
{
	if (nbr_a[0].nbr > nbr_a[1].nbr)
		sa(nbr_a);
	if (nbr_a[1].nbr > nbr_a[2].nbr)
	{
		ra(nbr_a);
		sa(nbr_a);
		rra(nbr_a);
	}
	if (nbr_a[0].nbr > nbr_a[1].nbr)
		sa(nbr_a);
}

static void	is_5(t_nbr *nbr_a, t_nbr *nbr_b, int argc)
{
	pb(nbr_a, nbr_b);
	pb(nbr_a, nbr_b);
	is_3(nbr_a);
	// test(nbr_a, nbr_a[0].size);
	// test(nbr_b, nbr_b[0].size);
	while (nbr_a[0].index < nbr_b[0].index)
		ra(nbr_a);
	pa(nbr_a, nbr_b);
	// test(nbr_a, nbr_a[0].size);
	// test(nbr_b, nbr_b[0].size);
	while (nbr_a[1].index - 1 != nbr_b[0].index)
		ra(nbr_a);
	ra(nbr_a);
	pa(nbr_a, nbr_b);
	// test(nbr_a, nbr_a[0].size);
	while (is_sort(nbr_a, argc, nbr_b, 1) != 0)
		ra(nbr_a);
	// test(nbr_a, nbr_a[0].size);
}

static void	specific_case(t_nbr *nbr_a, t_nbr *nbr_b, int argc)
{
	if (argc == 3)
	{
		sa(nbr_a);
		quit(nbr_a, nbr_b);
	}
	else if (argc == 4)
		is_3(nbr_a);
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
