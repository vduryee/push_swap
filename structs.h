/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:55:38 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/18 10:59:00 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

typedef	struct s_stack
{
	int		*values;
	size_t	size;
	size_t	capacity;
}	t_stack;

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

typedef	struct	s_data
{
	t_stack		a;
	t_stack		b;
	t_counter	count;
	int			algo;
	int			bench;
}	t_data;

// values is a pointer to the 1st element (bottom) of the stack which is an array of ints.
// size is the number of elements currently in the stack
// capacity is the maximum number of elements the stack can hold, basically how much we told malloc to give us.

/* The capacity of both our stacks (A and B) will always be the same n,
	since to consider all scenarios, A or B could be filled with n values at some point;
	this will ensure us that we can always store what we need.*/

#endif