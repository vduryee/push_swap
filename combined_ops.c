/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:22 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/13 15:59:20 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

void dswap(t_stack *a, t_stack *b, t_counter *count)
{
	swap(a, count, 'a');
	swap(b, count, 'b');
	count->ss++;
}

void drotate(t_stack *a, t_stack *b, t_counter *count)
{
	rotate(a, count, 'a');
	rotate(b, count, 'b');
	count->rr++;
}

void drev_rotate(t_stack *a, t_stack *b, t_counter *count)
{
	rev_rotate(a, count, 'a');
	rev_rotate(b, count, 'b');
	count->rrr++;
}