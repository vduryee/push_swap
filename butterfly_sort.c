/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/25 08:17:39 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

void	butterfly_push_b(t_data *d, int box, int range)
{
	static int	i = 0;
	int	mid;

	mid = (box * range) - (range / 2);
	while (i < (box * range) && d->a.size != 0)
	{
		while (d->a.values[d->a.size - 1] > (box * range) - 1)
			rotate(&d->a, &d->count, 'a');
		push(&d->a, &d->b, &d->count, 'b');
		if (d->b.values[d->b.size - 1] < mid && d->b.size > 1)
			rotate(&d->b, &d->count, 'b');
		i++;
	}
}

int	verif_rotate(t_data *d, int i, int mid)
{
	int	j;

	j = 3;
	while (j < mid + 1)
	{
		if (d->b.values[d->b.size - j] == i - 1)
			return (1);
		j++;
	}
	return (0);
}

void	butterfly_move_in_b(t_data *d, int i, int range)
{
	int	mid;

	mid = range / 2;
	if (d->b.values[d->b.size - 2] == i - 1)
			swap(&d->b, &d->count, 'b');
	else if ((int)d->b.size > mid && verif_rotate(d, i, mid) == 1)
			rotate(&d->b, &d->count, 'b');
	else if (d->b.size > 0)
			rev_rotate(&d->b, &d->count, 'b');
}

void	butterfly_push_a_helper(t_data *d, int *i, int *p)
{
	*i = *i - 1;
	*p = 0;
	swap(&d->a, &d->count, 'a');
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

	i = 0;
	range = 10;
	if (d->a.capacity > 500 && d->a.capacity < 800)
		range = 20;
	else if (d->a.capacity > 800)
		range = 30;
	while (i < (int)(d->a.capacity / 10) + 1)
	{
		butterfly_push_b(d, i, range);
		i++;
	}
	while (i > 0)
	{
		butterfly_push_a(d, i ,range);
		i--;
	}
}
