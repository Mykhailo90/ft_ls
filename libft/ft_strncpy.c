/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:55:32 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:43:43 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strncpy(char *dest, const char *src, size_t n)
{
	char			*res;

	res = dest;
	while (n && (*dest++ = *src++))
		n--;
	if (n)
	{
		while (--n)
			*dest++ = '\0';
	}
	return (res);
}

unsigned char		*ft_strncpy_uv(unsigned char *dest,
									const unsigned char *src, size_t n)
{
	unsigned char	*res;

	res = dest;
	while (n && (*dest++ = *src++))
		n--;
	if (n)
	{
		while (--n)
			*dest++ = '\0';
	}
	return (res);
}
