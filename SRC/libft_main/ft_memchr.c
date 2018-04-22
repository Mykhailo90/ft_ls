/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:51:52 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:08:23 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s && !n)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char *)(s) == (unsigned char)c)
			return ((unsigned char *)s);
		s++;
	}
	return (NULL);
}
