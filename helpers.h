/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:25:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/19 12:30:50 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

void	ft_normalize(t_stack *a);
int     ft_strcmp (const char *s1, const char *s2);
int     algo_selector(char *arg);
int 	bench_check(char *arg);
int		ft_init(t_data *d, int ac, char **av);
double	compute_disorder(t_stack *a);
void	print_disorder(double disorder);
int		count_ops(t_counter count);
char 	*bench_algo(t_data d);
void	print_bench(t_data d);


#endif