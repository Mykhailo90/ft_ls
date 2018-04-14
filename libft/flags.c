/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:51:49 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/19 18:51:51 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_it_flags(char ch)
{
	if (ch == ' ' || ch == '-' || ch == '+' || ch == '#')
		return (1);
	return (0);
}

int		search_fl_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (str[0] == '0')
			return (1);
		if (str[i] == '0' && (str[i - 1] == '%' ||
			is_it_flags(str[i - 1]) || is_it_size(str[i - 1])))
			return (1);
		i++;
	}
	return (0);
}

int		search_dif_fl(char *str, char x)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (str[i] == x)
			return (1);
		i++;
	}
	return (0);
}

void	search_flags(char *str)
{
	int	i;

	i = 0;
	if (search_dif_fl(str, '+'))
		g_com.flags[i++] = '+';
	if (search_dif_fl(str, '-'))
		g_com.flags[i++] = '-';
	if (search_dif_fl(str, '#'))
		g_com.flags[i++] = '#';
	if (search_dif_fl(str, ' '))
		g_com.flags[i++] = ' ';
	if (search_fl_n(str))
		g_com.flags[i++] = '0';
}
