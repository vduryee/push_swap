/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:55:38 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/11 12:10:57 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef	struct s_stack
{
	int		*values;
	size_t	size;
	size_t	capacity;
}	t_stack;

// values is a pointer to the 1st element (bottom) of the stack which is an array of ints.
// size is the number of elements currently in the stack
// capacity is the maximum number of elements the stack can hold, basically how much we told malloc to give us.

/* The capacity of both our stacks (A and B) will always be the same n,
	since to consider all scenarios, A or B could be filled with n values at some point;
	this will ensure us that we can always store what we need.*/