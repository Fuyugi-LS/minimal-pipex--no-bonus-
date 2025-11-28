/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:50:37 by nsongsit          #+#    #+#             */
/*   Updated: 2025/08/31 19:05:41 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned char	*p;

	if (!s)
		return (NULL);
	i = (unsigned char)c;
	p = (unsigned char *)s;
	while (n--)
		p[n] = i;
	return (s);
}
