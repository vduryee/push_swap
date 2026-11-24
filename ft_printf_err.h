/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:54:33 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/24 13:31:31 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_ERR_H
# define FT_PRINTF_ERR_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar_err(char c);
int	ft_putstr_err(char *str);
int	ft_putnbr_err(int n);
int	ft_printf_err(const char *format, ...);

#endif
