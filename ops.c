/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:42:44 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/24 18:26:43 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ops.h"

void	swap(t_stack *s, t_counter *count, char c)
{
	int	tmp;

	if (s->size > 1)
	{
		tmp = s->values[s->size - 1];
		s->values[s->size - 1] = s->values[s->size - 2];
		s->values[s->size - 2] = tmp;
	}
	if (c == 'a')
		count->sa++;
	else if (c == 'b')
		count->sb++;
	ft_printf(s->flag, "s%c\n", c);
}

void	push(t_stack *from, t_stack *to, t_counter *count, char c)
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
	if (c == 'a')
		count->pa++;
	else if (c == 'b')
		count->pb++;
	ft_printf(from->flag, "p%c\n", c);

}

void	rev_rotate(t_stack *s, t_counter *count, char c)
{
	int		tmp;
	size_t	i;
	int		j;

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
	if (c == 'a')
		count->rra++;
	else if (c == 'b')
		count->rrb++;
	ft_printf(s->flag, "rr%c\n", c);

}

void	rotate(t_stack *s, t_counter *count, char c)
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
	if (c == 'a')
		count->ra++;
	else if (c == 'b')
		count->rb++;
	ft_printf(s->flag, "r%c\n", c);
}
