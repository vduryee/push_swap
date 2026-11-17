/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:20:54 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/17 22:11:47 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

#include "structs.h"

void	swap(t_stack *s, t_counter *count, char c);
void	push(t_stack *to, t_stack *from, t_counter *count, char c);
void	rotate(t_stack *s, t_counter *count, char c);
void	rev_rotate(t_stack *s, t_counter *count, char c);
void	dswap(t_stack *a, t_stack *b, t_counter *count);
void	drotate(t_stack *a, t_stack *b, t_counter *count);
void	drev_rotate(t_stack *a, t_stack *b, t_counter *count);

#endif