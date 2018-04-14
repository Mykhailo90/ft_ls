/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_esp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:04:51 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/24 17:04:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_esp(char **str)
{
	int					len_numb;
	int					width;
	char				*tmp;
	int					i;

	i = 0;
	len_numb = (int)ft_strlen(*str);
	if ((*str)[0] == '\0' && g_com.specificator != 'd')
	{
		len_numb++;
	}
	width = ft_atoi(g_com.width);
	tmp = ft_strnew(width - len_numb);
	while (i < (width - len_numb))
		tmp[i++] = ' ';
	*str = (input_symb(g_com.flags, '-')) ?
		ft_strjoin(*str, tmp) : ft_strjoin(tmp, *str);
}

void					add_esp_for_c_end(char ch)
{
	int					width;
	int					i;

	i = 0;
	width = ft_atoi(g_com.width);
	print_symbol(ch);
	while (i++ < width - 1)
		print_symbol(' ');
}

void					print_symbol(char symbol)
{
	if (g_print < g_size)
		g_buffer[g_print++] = symbol;
	else
	{
		g_print_len += g_print;
		write(1, g_buffer, g_print);
		ft_bzero(g_buffer, g_size);
		g_print = 0;
		g_buffer[g_print++] = symbol;
	}
}

void					add_esp_for_c_part2(char symbol, int i, int len)
{
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) == 0 &&
													g_com.width[0] == '\0')
		print_symbol(' ');
	else
		print_symbol(symbol);
	while (i++ < len)
		print_symbol(' ');
}

void					add_esp_for_c(char symbol)
{
	int					width;
	int					i;
	int					len;

	i = 0;
	width = ft_atoi(g_com.width);
	len = width - 1;
	if (!input_symb(g_com.flags, '-'))
	{
		while (i++ < len)
			print_symbol(' ');
		if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) == 0 &&
			g_com.width[0] == '\0')
			print_symbol(' ');
		else
			print_symbol(symbol);
	}
	else
		add_esp_for_c_part2(symbol, i, len);
}
