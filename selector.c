/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:16:25 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/24 17:28:08 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp (const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int algo_selector(char *arg)
{
    if(!ft_strcmp(arg, "--simple"))
        return (1);
    if(!ft_strcmp(arg, "--medium"))
        return (2);
    if(!ft_strcmp(arg, "--complex"))
        return (3);
    if(!ft_strcmp(arg, "--adaptive"))
        return (0);
    return (-1);
}

int bench_check(char *arg)
{
	if(!ft_strcmp(arg, "--bench"))
		return (1);
	return (0);
}

int live_check(char *arg)
{
	if(!ft_strcmp(arg, "--live"))
		return (1);
	return (0);
}