/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:42:44 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/13 12:16:30 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->size > 1)
	{
		tmp = s->values[s->size - 1];
		s->values[s->size - 1] = s->values[s->size - 2];
		s->values[s->size - 2] = tmp;
	}
}

void	push(t_stack *from, t_stack *to)
{
	if(!from || !to)
		return ;
	if (from->size > 0)
	{
		to->values[to->size] = from->values[from->size - 1];
		from->values[from->size - 1] = 0;
		to->size++;
		from->size--;
	}
}

void	rotate(t_stack *s)
{
	int	tmp;
	unsigned long	i;
	int	j;

	if(!s)
		return ;
	i = 0;
	j = 1;
	tmp = s->values[i];
	while (i < s->size - 1)
	{
		i = j - 1;
		s->values[i] = s->values[j];
		j++;
	}
	s->values[i] = tmp;
}

void	rev_rotate(t_stack *s)
{
	int	tmp;
	int	i;
	int	j;

	if(!s)
		return ;
	i = s->size - 1;
	tmp = s->values[i];
	while (i > 0)
	{
		j = i - 1;
		s->values[i] = s->values[j];
		i--;
	}
	s->values[j] = tmp;
}
