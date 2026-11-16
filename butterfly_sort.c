/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegaspa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:55:04 by alegaspa          #+#    #+#             */
/*   Updated: 2026/11/16 17:10:46 by alegaspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i != nb) && i < nb)
		i++;
	return (i);
}

void	butterfly_push(t_stack *a, t_stack *b, t_counter *count)
{
	size_t	size_box;
	size_t	n_box;

	size_box = 1.5 * (ft_sqrt((int)a->capacity));
	n_box = (a->capacity / size_box) + 1;
	while
	{
		while (debut < fin)
		{
			while (a->values[0] > box_size)
				rev_rotate(a, count,'a');
			push(a, b, count,'a');
			if (valeur < mid)
				rev_rotate(b, count, 'b');
			debut++;
		}
