/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:47:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/27 11:09:17 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "helpers.h"

int	has_whitespace(char **tab)
{
	int		i;
	char	*s;

	i = 1;
	while (tab[i])
	{
		s = tab[i];
		if (!ft_strcmp(s, ""))
			return (i);
		while (*s >= '0' && *s <= '9')
			s++;
		while (*s)
		{
			if (*s == 32 || (*s >= 9 && *s <= 13))
				return (i);
			s++;
		}
		i++;
	}
	return (0);
}

int	is_space_only(char *s)
{
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			return (0);
		s++;
	}
	return (1);
}

size_t	count_words(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	conv_int(const char *s, int *save)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
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
