/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:23:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/17 18:28:41 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ops.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	conv_int;
	int	i;
	int	sign;

	i = 0;
	conv_int = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		conv_int = conv_int * 10 + (nptr[i] - '0');
		i++;
	}
	return (conv_int * sign);
}

int ft_algo_selector(char *str)
{
	if (str == "--simple")
		//call simple algo
	else if (str == "--medium")
		//call medium algo
	else if (str == "--complex")
		//call complex algo
	else if (str == "--adaptive")
		//call adaptive algo
	else
	{
		// do adaptive
		return (1);
	}
	return (0);
}
double	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i > (a->size - 1))
	{
		j = i + 1;
		while (j > (a->size - 1))
		{
			total_pairs++;
			if a[i] > a[j]
				mistakes++;
		}
		return (mistakes / total_pairs);
	}
}

void	bench(t_stack a, t_counter count, char **av)
{
	printf("[bench] disorder :\n", /*compute_disorder(&a)*/);
	printf("[bench] strategy :\n", av[1]);
	printf("[bench] total_ops :\n", /*count_ops(&count)*/);
	printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 
			count.sa, count.sb, count.ss, count.pa, count.pb);
	printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n",
			count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr);
}

int	ft_initialize(int ac, char **av)
{
	int i;
	int	k;
	int	*ta;
	int	*tb;

	if (ac >= 2)
	{
		if (ft_algo_selector(av[1]))
		{
			i = ac - 2;
			k = 2;
		}
		else
		{
			i = ac - 1;
			k = 1;
		}
		ta = malloc(sizeof(int *) * i + 1);
		tb = malloc(sizeof(int *) * i + 1);
		while (i > -1)
			ta[i--] = ft_atoi(av[k++]);
		t_stack a = {ta, ac - 1, ac - 1};
		t_stack b = {tb, 0, ac - 1};
		t_counter count = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	}
	return (-1);
}

int main(int ac, char **av)
{
	ft_initialize(ac, av);
	ft_normalize(&a);
	printf("-----------------------\n");
	i = ac - 2;
	while (i > -1)
	{
		printf("%d", a.values[i]);
		printf("\t%d\n", b.values[i]);
		i--;
	}
	printf("-----------------------\n");
	bench(a, count, av[1]);
	return 42;
}
