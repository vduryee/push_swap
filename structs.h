/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:55:38 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/25 16:47:42 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft/libft.h"
# include "ft_printf.h"
# include "ft_printf_err.h"
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		*values;
	size_t	size;
	size_t	capacity;
}	t_stack;

typedef struct s_counter
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	ss;
	int	rr;
	int	rrr;
}	t_counter;

typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	t_counter	count;
	int			algo;
	int			bench;
	int			init;
	double		disorder;
}	t_data;

#endif