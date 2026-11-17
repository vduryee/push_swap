/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 09:58:01 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/17 22:11:55 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static int	get_max(t_stack *a)
{
	int	i;
	int	max;
	static long	save_max = 2147483648;

	i = 0;
	max = -2147483648;
	while (i < (int)a->capacity)
	{
		if (max < a->values[i] && a->values[i] < save_max) 
			max = a->values[i];
		i++;
	}
	save_max = max;
	return (max);
}

static int	get_min(t_stack *a)
{
	int	i;
	int	min;
	static long	save_min = -2147483649;

	i = 0;
	min = 2147483647;
	while (i < (int)a->capacity)
	{
		if (min > a->values[i] && a->values[i] > save_min)
			min = a->values[i];
		i++;
	}
	save_min = min;
	return (min);
}

static int	*parse(t_stack *a)
{
	int	j;
	int	*tmp;
	int	checkpt;

	checkpt = 0;
	j = (a->capacity - 1);
	tmp = malloc(sizeof(int *) * a->capacity);
	if (!tmp)
		return (NULL);
	while (checkpt <= j)
	{
		tmp[checkpt] = get_min(a);
		tmp[j] = get_max(a);
		checkpt++;
		j--;
	}
	return (tmp);
}		

void	ft_normalize(t_stack *a)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	i = 0;
	tmp = parse(a);
	while (i < a->capacity)
	{
		j = 0;
		while (j < a->capacity)
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
