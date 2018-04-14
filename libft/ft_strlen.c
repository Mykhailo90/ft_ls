/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:13:09 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/05 12:42:42 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	while (*(s++) != '\0')
		count++;
	return (count);
}

size_t			ft_strlen_uv(const unsigned char *s)
{
	size_t		count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
