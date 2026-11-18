/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/18 17:23:52 by alegaspa         ###   ########.fr       */
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

void	butterfly_push_b(t_stack *a, t_stack *b, t_counter *count, int box)
{
	static int	i = 0;
	int	range;
	int	mid;

	range = 10;
	mid = (box * range) - (range / 2);
	if (a->capacity > 500)
		range = 1.5 * ft_sqrt(a->capacity);
	while (i < (box * range) && a->size != 0)
	{
		while (a->values[a->size - 1] > (box * range) - 1)
			rotate(a, count, 'a');
		push(a, b, count, 'b');
		if (b->values[b->size - 1] < mid && b->size > 1)
			rotate(b, count, 'b');
		i++;
	}
}

void	butterfly_push_a(t_stack *a, t_stack *b, t_counter *count)
{
	static int	i = b->size;
	int	range;
	int	mid;
	int	j;

	range = 10;
	mid = (box * range) - (range / 2);
	j = 0;
	if (i > (box - 1) * range && i < mid)
	{
		while (j < mid)
		{
			rev_rotate(b, count, 'b');
			if (b->values[b->size - 1] == i - 1)
			{
				push(b, a, count, 'a');
				i--;
			}
			j++;
		}
	}
	while (i > (box - 1) * range)
	{
		if (b->size - 2 == i - 1)
			swap(b, count, 'b');
		else  
			rotate(b, count, 'b');
		if (

void	butterfly_sort(t_stack *a, t_stack *b, t_counter *count)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		butterfly_push_b(a, b, count, i);
		i++;
	}
}
