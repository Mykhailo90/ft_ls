/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:13:11 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:12:36 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;

	if (!size)
		return (NULL);
	if (!(p = (unsigned char *)malloc(size)))
		return (NULL);
	bzero(p, size);
	return (p);
}
