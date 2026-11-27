/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:43:53 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/27 11:12:45 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "algo_sort.h"

void	adaptive_sort(t_data *d)
{
	if (d->disorder < 0.2)
		insert_sort(d);
	else if (d->disorder >= 0.2 && d->disorder < 0.5)
		butterfly_sort(d);
	else if (d->disorder >= 0.5)
		radix_sort(&d);
}
