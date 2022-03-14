/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:08:52 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/11 17:26:19 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexing(t_nbr *nbr, int argc)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	while (argc - 1 > ++i)
	{
		index = 0;
		j = -1;
		while (argc - 1 > ++j)
			if (nbr[i].nbr > nbr[j].nbr)
				index++;
		nbr[i].index = index;
	}
}

int	is_sort(t_nbr *nbr_a, int argc, t_nbr *nbr_b, int time)
{
	int	i;
	int	j;
	int	r;
	int	size;

	if (time == 0)
	{
		indexing(nbr_a, argc);
		nbr_a[0].size = argc - 1;
		nbr_b[0].size = 0;
	}
	size = nbr_a[0].size;
	i = -1;
	r = 0;
	while (size > ++i)
	{
		j = i;
		while (size > ++j)
			if (nbr_a[i].nbr > nbr_a[j].nbr)
				r++;
	}
	return (r);
}

static void	duplicate(t_nbr *nbr, int argc, t_nbr *nbr_b)
{
	int	i;
	int	j;

	i = -1;
	while (argc - 1 > ++i)
	{
		if (nbr[i].nbr > 2147483647 || nbr[i].nbr < -2147483648)
			error(nbr, nbr_b);
		j = i;
		while (argc - 1 > ++j)
			if (nbr[i].nbr == nbr[j].nbr)
				error(nbr, nbr_b);
	}
}

void	parsing(char **argv, t_nbr *nbr_a, int argc, t_nbr *nbr_b)
{
	int		i;
	int		j;
	int		tab;
	int		space;

	i = 0;
	tab = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '\0')
			error(nbr_a, nbr_b);
		j = -1;
		space = 0;
		while (argv[i][++j] && &nbr_a[tab])
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-') ||
				(argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				error(nbr_a, nbr_b);
		nbr_a[tab].nbr = ft_atoi(argv[i]);
		tab++;
	}
	duplicate(nbr_a, argc, nbr_b);
	if (is_sort(nbr_a, argc, nbr_b, 0) == 0)
		quit(nbr_a, nbr_b);
}
