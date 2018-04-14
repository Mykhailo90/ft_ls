/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:53:38 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:09:05 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	if (!dest && !n)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (n--)
	{
		if (*src1 != (unsigned char)c)
			*(dest1++) = *(src1++);
		else
		{
			*(dest1++) = *(src1++);
			return (dest1);
		}
	}
	return (NULL);
}
