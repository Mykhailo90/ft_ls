/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:05:19 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 14:09:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*sr;
	char	*d1;
	size_t	count;

	d1 = (char *)dest;
	sr = (char *)src;
	count = 0;
	if (sr < d1)
		while (n--)
			d1[n] = sr[n];
	else
		ft_memcpy(d1, sr, n);
	return (d1);
}
