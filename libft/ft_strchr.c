/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsongsit <nsongsit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:02:46 by nsongsit          #+#    #+#             */
/*   Updated: 2025/09/01 14:02:47 by nsongsit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	fchar;

	fchar = (char)c;
	while (*s != '\0')
	{
		if (*s == fchar)
			return ((char *) s);
		s += 1;
	}
	if (fchar == '\0')
		return ((char *) s);
	return (NULL);
}
