/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:31:46 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/27 13:38:25 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "bonus.h"

static int	split_args()
{
	
}

static int	check_args(t_data d, char *str)
{
	static const char	*args[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rra", "rrb", "rrr"};
	int		i;

	i = 0;
	while (i < 11)
	{
		if(!ft_strcmp(str, args[i]))
			return (1);
		i++;
	}
	return (0);
}

static int checker_helper(t_data d)
{
	int	i;

	i = 0;
	while (i < d.a.size -1)
	{
		if (d.a.values[i] > d.a.values[i + 1])
		{
			write(1, "KO\n", 3);
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_data	d;
	char 	buffer[4];
	int		i;

	if (ac > 2)
	{
		d.init = ft_init(&d, ac, av);
		if (!d.init)
			return (write(2, "Error\n", 6));
	}
	else
	{
		while (read(0, buffer, sizeof(buffer)) > 0)
		{
			
		}
		if (checker_helper(d))
			write (1, "OK\n", 3);
	}
	return (0);
}
