/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:10:56 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/20 09:53:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_symbols(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr_ptr;
	size_t		len;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	j = ft_count_words(s, c);
	i = 0;
	arr_ptr = NULL;
	if (!(arr_ptr = (char **)ft_memalloc(sizeof(s) * j + 1)))
		return (NULL);
	while (j--)
	{
		len = count_symbols(s, c);
		if (!(arr_ptr[i] = ft_memalloc(sizeof(s) * len + 1)))
			return (NULL);
		while (*s == c)
			s++;
		ft_strncpy(arr_ptr[i], s, len);
		s = s + len;
		i++;
	}
	arr_ptr[i] = 0;
	return (arr_ptr);
}
