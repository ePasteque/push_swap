/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:34:17 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/24 14:19:41 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 7);
	exit(1);
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

int	main(int argc, char **argv)
{
	t_nbr	*nbr;
	int		i;

	if (argc < 2)
		error();
	nbr = malloc(sizeof(t_nbr) * (argc - 1));
	if (!nbr)
		error();
	parsing(argv, nbr, argc);
	i = -1;
	while (argc - 2 > i)
	{
		printf("num = %ld\n", nbr[++i].nbr);
	}
	free(nbr);
	return (0);
}
