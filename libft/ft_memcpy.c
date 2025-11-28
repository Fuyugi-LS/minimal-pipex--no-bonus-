/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:06:14 by nsongsit          #+#    #+#             */
/*   Updated: 2025/08/31 21:43:39 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	while (i < n)
	{
		a[i] = b[i];
		i += 1;
	}
	return (dest);
}
