/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:20:54 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/13 11:17:30 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

#include "push_swap.h"

int	swap(t_stack *s);
int	push(t_stack *to, t_stack *from);
int	rotate(t_stack *s);
int	rev_rotate(t_stack *s);
int dswap(t_stack *a, t_stack *b);
int drotate(t_stack *a, t_stack *b);
int drev_rotate(t_stack *a, t_stack *b);

#endif