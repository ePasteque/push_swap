/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:33:38 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/24 14:17:41 by lbattest         ###   ########.fr       */
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
}				t_nbr;

typedef struct s_utils
{
	int		i;
	int		j;
	int		space;
	int		elem_count;
}				t_utils;

void	error(void);
void	parsing(char **argv, t_nbr *nbr, int argc);
void	*free_all(char **str);

#endif
