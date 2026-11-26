/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:25:59 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/26 17:41:32 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

int better_ft_init(t_data *d, int ac, char **av)
{
	char	*str;
	char	*tmp;
	int		fst;
	int 	words;
	
	fst = flag_checker(d, ac, av);
	words = ac - fst;
	d->a.values = NULL;
	d->b.values = NULL;
	d->count = (t_counter){0};
	d->space = has_whitespace(av);
	str = ft_strdup(av[fst]);
	if (!is_space_only(av[d->space]))
	{
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
	}
	return (0);
}
