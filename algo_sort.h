/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:53:03 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/25 15:46:16 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_SORT_H
# define ALGO_SORT_H

#include "structs.h"

void	insert_sort(t_data *d);
void	butterfly_sort(t_data *d);
void 	adaptive_sort(t_data *d);

#endif
