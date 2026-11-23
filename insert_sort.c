/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:00:33 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/23 15:29:29 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

void	insert_push_b(t_data *d)
{
	int	min;

	min = 0;
	while (d->a.size != 0)
	{
		if(min == d->a.values[d->a.size - 1])
		{
			push(&d->a, &d->b, &d->count, 'a');
			min++;
		}
		else
			rotate(&d->a, &d->count, 'a');
		
	}
}

void	insert_push_a(t_data *d)
{
	while (d->b.size != 0)
		push(&d->b, &d->a, &d->count, 'b');
}

void	insert_sort(t_data *d)
{
	while (d->a.size != 0)
		insert_push_b(d);
	while (d->b.size != 0)
		insert_push_a(d);
}