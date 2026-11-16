/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 09:58:01 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/16 10:14:20 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	get_max(t_struct *a, size_t a->capacity)
{
	int	i;
	int	max;
	static long	save = INT_MAX + 1;

	i = 0;
	max = a->values[0];
	while (i < (int)a->capacity)
	{
		if (max < a->values[i] && a->values[i] < save_max) 
			max = a->values[i];
		i++;
	}
	save_max = max;
	return (max);
}

static int	get_min(t_struct *a, size_t a->capacity)
{
	int	i;
	int	min;
	static long	save_min = INT_MIN - 1;

	i = checkpt;
	min = a->values[0];
	while (i < (int)a->capacity)
	{
		if (min > a->values[i] && a->values[i] > save_min)
			min = a->values[i];
		i++;
	}
	save_min = min;
	return (min);
}

static int	*parse(t_struct *a)
{
	int	j;
	int	*tmp;
	int	checkpt;

	checkpt = 0;
	j = a->capacity - checkpt;
	tmp = malloc(sizeof(int) * a->capacity);
	if (!tmp)
		return (NULL);
	while (checkpt < j)
	{
		tmp [checkpt] = get_min(a, a->capacity);
		tmp [j] = get_max(a, a->capacity);
		checkpt++;
	}
	return (tmp);
}		

void	ft_normalize(t_struct *a)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	tmp = parse(a);
	while (i < a->capacity)
	{
		j = 0;
		while (j < a->values)
		{
			if (a->values[i] == tmp[j])
			{
				a->values[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(tmp);
}
