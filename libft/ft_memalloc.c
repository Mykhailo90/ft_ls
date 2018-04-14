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

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (!size)
		return (NULL);
	if (!(p = malloc(size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
