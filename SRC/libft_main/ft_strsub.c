/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:45:12 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:47:00 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*res;

	if (!s)
		return (NULL);
	res = NULL;
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	ft_strncpy(res, &s[start], len);
	return (res);
}
