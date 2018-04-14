/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:00:49 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/19 20:00:50 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_it_size(char ch)
{
	if (ch == 'j' || ch == 'L' || ch == 'z' || ch == 't' || ch == 'h' ||
		ch == 'l')
		return (1);
	else
		return (0);
}

int			check_size(char ch)
{
	int		i;

	i = 0;
	while (g_com.size[i] != '\0')
	{
		if (g_com.size[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

size_t		len_s(char *str)
{
	size_t	i;

	i = 0;
	while (is_it_size(str[i]))
		i++;
	return (i);
}

int			search_hl(char *str)
{
	int		i;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h' && check_size('1') == 0)
	{
		while (g_com.size[i] != '\0')
			i++;
		g_com.size[i] = '1';
		return (1);
	}
	if (str[i] == 'l' && str[i + 1] == 'l' && check_size('2') == 0)
	{
		while (g_com.size[i] != '\0')
			i++;
		g_com.size[i] = '2';
		return (1);
	}
	return (0);
}

void		search_size(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (is_it_size(str[i]) && search_hl(&str[i]))
			i++;
		else if (is_it_size(str[i]) && check_size(str[i]) == 0)
		{
			while (g_com.size[n] != '\0')
				n++;
			g_com.size[n] = str[i];
		}
		i++;
	}
}
