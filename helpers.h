/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:25:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/26 17:14:12 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

void	ft_normalize(t_stack *a);
int		ft_strcmp(const char *s1, const char *s2);
int		algo_selector(char *arg);
int		bench_check(char *arg);
int		ft_init(t_data *d, int ac, char **av);
int 	better_ft_init(t_data *d, int ac, char **av);
int		flag_checker(t_data *d, int ac, char **av);
double	compute_disorder(t_stack *a);
void	print_disorder(double disorder);
int		count_ops(t_counter count);
char	*bench_algo(t_data d);
void	print_bench(t_data d);
int		has_whitespace(char **tab);
int		is_space_only(char *s);
int 	ft_init_helper(t_data *d, int words, char *str);
size_t	count_words(char **tab);
void	free_tab(char **tab);
int		algo_first_flag(t_data *d, int ac, char **av);
int		bench_first_flag(t_data *d, int ac, char **av);

#endif