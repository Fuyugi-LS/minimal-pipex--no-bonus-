/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:29:27 by nsongsit          #+#    #+#             */
/*   Updated: 2025/11/09 04:01:30 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlen(const char *s)
{
	const char	*i;

	if (!s)
		return (-1);
	i = s;
	while (*i)
		i++;
	return ((size_t)(i - s));
}
