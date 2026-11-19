/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:47:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/19 15:02:08 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	has_whitespace(const char *s)
{
	while (*s)
	{
		if ((*s == 32) || (*s >= 9 && *s <= 13))
			return (1);
		s++;
	}
	return (0);
}

size_t count_words(char **tab)
{
	size_t i;
	
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}