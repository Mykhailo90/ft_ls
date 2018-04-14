/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:12:20 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strcat(char *dest, const char *src)
{
	size_t			i;
	size_t			j;
	char			*st;

	i = 0;
	j = 0;
	st = dest;
	while (*(dest++) != '\0')
		i++;
	while (*(src++) != '\0')
		j++;
	src = src - j - 1;
	dest--;
	while (j--)
		*(dest++) = *(src++);
	*dest = '\0';
	return (st);
}

unsigned char		*ft_strcat_uv(unsigned char *dest, const unsigned char *src)
{
	size_t			i;
	size_t			j;
	unsigned char	*st;

	i = 0;
	j = 0;
	st = dest;
	while (*(dest++) != '\0')
		i++;
	while (*(src++) != '\0')
		j++;
	src = src - j - 1;
	dest--;
	while (j--)
		*(dest++) = *(src++);
	*dest = '\0';
	return (st);
}
