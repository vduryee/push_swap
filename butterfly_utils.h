/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 09:04:48 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/26 09:18:47 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTERFLY_UTILS_H
# define BUTTERFLY_UTILS_H

# include "structs.h"
# include "ops.h"

void	rotate_selector(t_data *d, int finder);
void	hide_and_seek_butterfly(t_data *d, int box, int range);
int		verif_rotate(t_data *d, int i, int mid);
void	butterfly_move_in_b(t_data *d, int i, int range);
void	butterfly_push_a_helper(t_data *d, int *i, int *p);

#endif
