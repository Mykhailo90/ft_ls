/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:36:53 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:35:41 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*res;
	size_t		i;
	size_t		j;

	if (!s || !f)
		return (NULL);
	res = NULL;
	i = 0;
	j = 0;
	while (s[i])
		i++;
	if (!(res = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s[j])
	{
		res[j] = f(s[j]);
		j++;
	}
	res[j] = '\0';
	return (res);
}
