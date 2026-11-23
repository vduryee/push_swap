/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/23 16:54:14 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i != nb) && i < nb)
		i++;
	return (i);
}

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

void	butterfly_move_in_b(t_data *d, int i)
{
	if (d->b.values[d->b.size - 2] == i - 1)
			swap(&d->b, &d->count, 'b');
	else if (d->b.size > 5 && (d->b.values[d->b.size - 3] == i - 1 || d->b.values[d->b.size - 4] == i - 1 || d->b.values[d->b.size - 5] == i - 1))
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
			butterfly_move_in_b(d, i);
	}
}

void	butterfly_sort(t_data *d)
{
	int	i;
	int	range;

	i = 0;
	range = 10;
	if (d->a.capacity > 500)
		range = 1.5 * ft_sqrt(d->a.capacity);
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
