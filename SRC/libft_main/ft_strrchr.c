/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 10:22:07 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/13 17:36:09 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	if (!c)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == c)
			res = (char *)s;
		s++;
	}
	return (res);
}
