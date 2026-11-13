/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:20:54 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/13 15:48:35 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

#include "push_swap.h"

typedef struct s_counter
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int rra;
	int	rrb;
	int ss;
	int rr;
	int rrr;
} t_counter;

void	swap(t_stack *s, t_counter *count, char c);
void	push(t_stack *to, t_stack *from, t_counter *count, char c);
void	rotate(t_stack *s, t_counter *count, char c);
void	rev_rotate(t_stack *s, t_counter *count, char c);
void	dswap(t_stack *a, t_stack *b, t_counter *count);
void	drotate(t_stack *a, t_stack *b, t_counter *count);
void	drev_rotate(t_stack *a, t_stack *b, t_counter *count);

#endif