/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:12:40 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 16:05:46 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	char	*start;
	size_t	tmp;
	size_t	len;

	if (!s)
		return (NULL);
	tmp = 0;
	len = ft_strlen(s);
	while (is_space(*(s++)))
		tmp++;
	s = s - 1;
	if (*s == '\0')
		return (ft_memalloc(1));
	start = (char *)s;
	s = start + len - tmp - 1;
	while (is_space(*(s--)))
		tmp++;
	s = s + 1;
	if (!(res = ft_memalloc(len - tmp + 1)))
		return (NULL);
	ft_strncpy(res, start, (len - tmp));
	return (res);
}
