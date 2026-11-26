/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:00:33 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/26 09:44:08 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

void	hide_and_seek_insert(t_data *d, int min)
{
	int	finder;

	finder = 0;
	while (d->a.values[finder] != min)
		finder++;
	if (finder < (int)d->a.size / 2)
		rev_rotate(&d->a, &d->count, 'a');
	else
		rotate(&d->a, &d->count, 'a');
}

void	insert_push_b_helper(t_data *d, int *min, int *p)
{
	*min = *min + 1;
	*p = 0;
	swap(&d->b, &d->count, 'b');
}

void	insert_push_b(t_data *d)
{
	int	min;
	int	p;

	min = 0;
	p = 0;
	while (d->a.size != 0)
	{
		if (min == d->a.values[d->a.size - 1])
		{
			push(&d->a, &d->b, &d->count, 'b');
			min++;
			if (p == 1)
				insert_push_b_helper(d, &min, &p);
		}
		else if (min + 1 == d->a.values[d->a.size - 1])
		{
			push(&d->a, &d->b, &d->count, 'b');
			p = 1;
		}
		else
			hide_and_seek_insert(d, min);
	}
}

void	insert_push_a(t_data *d)
{
	while (d->b.size != 0)
		push(&d->b, &d->a, &d->count, 'a');
}

void	insert_sort(t_data *d)
{
	insert_push_b(d);
	insert_push_a(d);
}
