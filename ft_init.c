/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:15:39 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/27 10:33:59 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

static int	stack_init(t_stack *s, size_t n)
{
	s->values = malloc(sizeof(int) * (n + 1));
	if (s->values == NULL)
		return (0);
	s->size = 0;
	s->capacity = n;
	return (1);
}

int	flag_checker(t_data *d, int ac, char **av)
{
	if (!ft_strcmp(av[1], "--bench"))
		return (bench_first_flag(d, ac, av));
	return (algo_first_flag(d, ac, av));
}

int ft_init_helper(t_data *d, int words, char *str)
{
	int		init;
	char	**tab;

	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	free(str);
	words = count_words(tab);
	init = stack_init(&d->a, words) && stack_init(&d->b, words)
		&& fill_stack(&d->a, words, tab);
	free_tab(tab);
	return (init);
}

static int	join_args(t_data *d, char **av, int words, int fst)
{
	char	*str;
	char	*tmp;
	
	str = ft_strdup(av[fst]);
	while (av[fst])
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		fst++;
		if (av[fst] == 0)
			return(ft_init_helper(d, words, str));
		tmp = ft_strjoin(str, av[fst]);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	return (0);
}

int ft_init(t_data *d, int ac, char **av)
{
	int		str;
	int		fst;
	int 	words;
	
	fst = flag_checker(d, ac, av);
	words = ac - fst;
	d->a.values = NULL;
	d->b.values = NULL;
	d->count = (t_counter){0};
	d->space = has_whitespace(av);
	if (d->space)
	{
		if (is_space_only(av[d->space]))
			return (0);
	}
	str = join_args(d, av, words, fst);
	if (!str)
		return (0);
	return (1);
}