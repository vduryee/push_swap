/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:15:39 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/26 11:55:54 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

static int	conv_int(const char *s, int *save)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	// while (*s == ' ' || (*s >= 9 && *s <= 13))
	// 	s++;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	if (*s < '0' || *s > '9')
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
	}
	if (*s)
		return (0);
	*save = (int)(n * sign);
	return (1);
}

static int	fill_stack(t_stack *a, size_t n, char **args)
{
	size_t	i;
	size_t	j;
	int		save;

	i = 0;
	while (n > i)
	{
		if (!conv_int(args[i], &save))
			return (0);
		j = 0;
		while (i > j)
		{
			if (a->values[n - 1 - j] == save)
				return (0);
			j++;
		}
		a->values[n - 1 - i] = save;
		i++;
	}
	a->size = n;
	return (1);
}

static int	stack_init(t_stack *s, size_t n)
{
	s->values = malloc(sizeof(int) * (n + 1));
	if (s->values == NULL)
		return (0);
	s->size = 0;
	s->capacity = n;
	return (1);
}

static int	flag_checker(t_data *d, int ac, char **av)
{
	if (!ft_strcmp(av[1], "--bench"))
		return (bench_first_flag(d, ac, av));
	return (algo_first_flag(d, ac, av));
}

int	ft_init(t_data *d, int ac, char **av)
{
	int		fst;
	int		words;

	fst = flag_checker(d, ac, av);
	d->a.values = NULL;
	d->b.values = NULL;
	d->count = (t_counter){0};
	words = ac - fst;
	d->space = has_whitespace(av);
	if (!is_space_only(av[d->space]))
		return (ft_init_helper(d, words, av));
	if (!stack_init(&d->a, words) || !stack_init(&d->b, words))
		return (0);
	return (fill_stack(&d->a, words, av + fst));
}

int ft_init_helper(t_data *d, int words, char **av)
{
	int		init;
	char	**tab;

	tab = ft_split(av[d->space], ' ');
	if (!tab)
		return (0);
	words = count_words(tab);
	init = stack_init(&d->a, words) && stack_init(&d->b, words)
		&& fill_stack(&d->a, words, tab);
	free_tab(tab);
	return (init);
}
