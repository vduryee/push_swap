/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:22 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/13 11:12:24 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return (1);
}

int drotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	return (1);
}

int drev_rotate(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	return (1);
}