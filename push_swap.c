/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:34:17 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/08 17:43:31 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_nbr *nbr_a, t_nbr *nbr_b)
{
	write(2, "Error\n", 7);
	quit(nbr_a, nbr_b);
}

void	*free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

void	quit(t_nbr *nbr_a, t_nbr *nbr_b)
{
	free(nbr_a);
	free(nbr_b);
	exit(0);
}

void	test(t_nbr *nbr_a, int size)
{
	int	i;

	i = -1;
	printf("size = %d\n", nbr_a[0].size);
	while (size > ++i)
	{
		printf("num = %ld 	index = %d\n", nbr_a[i].nbr, nbr_a[i].index);
	}
}

int	main(int argc, char **argv)
{
	t_nbr	*nbr_a;
	t_nbr	*nbr_b;

	nbr_a = malloc(sizeof(t_nbr) * (argc - 1));
	nbr_b = malloc(sizeof(t_nbr) * (argc - 1));
	if (!nbr_a || !nbr_b)
		error(nbr_a, nbr_b);
	if (argc < 2)
		error(nbr_a, nbr_b);
	parsing(argv, nbr_a, argc, nbr_b);
	radix(nbr_a, nbr_b, argc);
	// test(nbr_a, nbr_a[0].size);
	quit(nbr_a, nbr_b);
	return (0);
}
