/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/26 09:15:40 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"
#include "butterfly_utils.h"

void	butterfly_push_b(t_data *d, int box, int range)
{
	static int	i = 0;
	int			mid;

	mid = (box * range) - (range / 2);
	while (i < (box * range) && d->a.size != 0)
	{
		while (d->a.values[d->a.size - 1] > (box * range) - 1)
			hide_and_seek_butterfly(d, box, range);
		push(&d->a, &d->b, &d->count, 'b');
		if (d->b.values[d->b.size - 1] < mid && d->b.size > 1)
			rotate(&d->b, &d->count, 'b');
		i++;
	}
}

void	butterfly_push_a(t_data *d, int box, int range)
{
	int	i;
	int	p;

	p = 0;
	i = d->b.size;
	while (i > (box - 1) * range)
	{
		if (d->b.values[d->b.size - 1] == i - 1)
		{
			push(&d->b, &d->a, &d->count, 'a');
			i--;
			if (p == 1)
				butterfly_push_a_helper(d, &i, &p);
		}
		else if (d->b.values[d->b.size - 1] == i - 2 && p == 0)
		{
			push(&d->b, &d->a, &d->count, 'a');
			p = 1;
		}
		else
			butterfly_move_in_b(d, i, range);
	}
}

void	butterfly_sort(t_data *d)
{
	int	i;
	int	range;

	i = 1;
	range = 10;
	if (d->a.capacity > 99 && d->a.capacity < 500)
		range = 25;
	if (d->a.capacity > 499 && d->a.capacity < 800)
		range = 57;
	else if (d->a.capacity > 800)
		range = 88;
	while (i < (int)(d->a.capacity / 10) + 2)
	{
		butterfly_push_b(d, i, range);
		i++;
	}
	while (i > 0)
	{
		butterfly_push_a(d, i, range);
		i--;
	}
}
