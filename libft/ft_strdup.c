/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:05:11 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/20 17:40:30 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dst == NULL)
		return (0);
	ft_strlcpy(dst, s, (ft_strlen(s) + 1));
	return (dst);
}
