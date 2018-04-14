/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:24:18 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:41:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *s)
{
	size_t	i;
	char	*start;
	char	*temp;
	char	*res;

	i = 0;
	start = (char *)s;
	res = NULL;
	temp = NULL;
	while (*(start++))
		i++;
	temp = (char *)malloc(sizeof(char) * i + 1);
	if (!temp)
		return (0);
	res = temp;
	while (i--)
		*(temp++) = *(s++);
	*temp = '\0';
	return (res);
}
