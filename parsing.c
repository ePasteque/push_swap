/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:08:52 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/24 15:00:57 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	duplicate(t_nbr *nbr, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (argc - 1 > ++i)
	{
		if (nbr[i].nbr > 2147483647 || nbr[i].nbr < -2147483648)
			error();
		j = i;
		while (argc - 1 > ++j)
			if (nbr[i].nbr == nbr[j].nbr)
				error();
	}
}

void	parsing(char **argv, t_nbr *nbr, int argc)
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
			error();
		j = -1;
		space = 0;
		while (argv[i][++j] && &nbr[tab])
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != '-') ||
				(argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1])))
				error();
		nbr[tab].nbr = ft_atoi(argv[i]);
		tab++;
	}
	duplicate(nbr, argc);
}
