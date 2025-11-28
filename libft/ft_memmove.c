/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:43:00 by nsongsit          #+#    #+#             */
/*   Updated: 2025/09/01 00:49:16 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest || !src)
		return (NULL);
	i = 0;
	a = (unsigned char *) dest;
	b = (const unsigned char *) src;
	if (dest < src + n && dest >= src)
	{
		while (n--)
			a[n] = b[n];
	}
	else
	{
		while (i < n)
		{
			a[i] = b[i];
			i += 1;
		}
	}
	return (dest);
}
