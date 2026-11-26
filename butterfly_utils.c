/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 08:47:03 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/26 09:16:08 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

void	rotate_selector(t_data *d, int finder)
{
	if (finder > (int)d->a.size / 2)
		rotate(&d->a, &d->count, 'a');
	else
		rev_rotate(&d->a, &d->count, 'a');
}

void	hide_and_seek_butterfly(t_data *d, int box, int range)
{
	int	max_finder;
	int	min_finder;
	int	count;
	int	winner;

	winner = 0;
	max_finder = d->a.size - 1;
	min_finder = 0;
	count = 0;
	while (d->a.values[min_finder] > (box * range) - 1)
		min_finder++;
	while (d->a.values[max_finder] > (box * range) - 1)
	{
		max_finder--;
		count++;
	}
	if (count < min_finder + 1 || count == min_finder + 1)
		rotate_selector(d, max_finder);
	else
		rotate_selector(d, min_finder);
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
