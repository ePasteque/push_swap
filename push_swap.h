/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:33:38 by lbattest          #+#    #+#             */
/*   Updated: 2022/03/08 17:00:44 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_nbr
{
	long int	nbr;
	int			index;
	int			size;
}				t_nbr;

typedef struct s_utils
{
	int		i;
	int		j;
	int		space;
	int		elem_count;
}				t_utils;
void	test(t_nbr *nbr_a, int size);
void	error(t_nbr *nbr_a, t_nbr *nbr_b);
void	parsing(char **argv, t_nbr *nbr_a, int argc, t_nbr *nbr_b);
void	*free_all(char **str);
void	quit(t_nbr *nbr_a, t_nbr *nbr_b);
void	sa(t_nbr *nbr);
void	sb(t_nbr *nbr);
void	ss(t_nbr *nbr_a, t_nbr *nbr_b);
void	pa(t_nbr *nbr_a, t_nbr *nbr_b);
void	pb(t_nbr *nbr_a, t_nbr *nbr_b);
void	ra(t_nbr *nbr);
void	rb(t_nbr *nbr);
void	rr(t_nbr *nbr_a, t_nbr *nbr_b);
void	rra(t_nbr *nbr);
void	rrb(t_nbr *nbr);
void	rrr(t_nbr *nbr_a, t_nbr *nbr_b);
void	radix(t_nbr *nbr_a, t_nbr *nbr_b, int argc);
int		is_sort(t_nbr *nbr_a, int argc, t_nbr *nbr_b, int time);
#endif
