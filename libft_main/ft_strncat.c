/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:17:44 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:43:08 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src && n--)
	{
		dest[i] = *(src++);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
