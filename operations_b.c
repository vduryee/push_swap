/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:42:44 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/12 16:58:43 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	sb(t_stack *b)
{
	int	temp;

	if (b->size > 1)
	{
		temp = b->values[0];
		b->values[0] = b->values[1];
		b->values[1] = temp;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		b->values[b->size] = a->values[a->size - 1];
		b->size++;
		a->size--;
	}
	printf("%d\n", b->values[0]);
	printf("%d\n", b->size);
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	i;
	int	j;

	i = b->size - 1;

	tmp = b->values[i];
	while (i > 0)
	{
		j = i - 1;
		b->values[i] = b->values[j];
		i--;
	}
	b->values[j] = tmp;
}

void	rb(t_stack *b)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	tmp = b->values[i];
	while (i < b->size - 1)
	{
		i = j - 1;
		b->values[i] = b->values[j];
		j++;
	}
	b->values[i] = tmp;
}

