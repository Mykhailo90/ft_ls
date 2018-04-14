/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_du.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:40:58 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 13:40:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_null_in_s(char **res_str)
{
	int					len_ch;
	int					w;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = (int)ft_strlen(*res_str);
	w = ft_atoi(g_com.width);
	i = (!(*res_str)) ? w : (w - len_ch);
	tmp = ft_strnew(i);
	w = 0;
	while (w < i)
		tmp[w++] = '0';
	*res_str = ft_strjoin(tmp, *res_str);
}

void					prep_help(char **res)
{
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) >
		(int)ft_strlen(*res) && ft_atoi(*res) >= 0)
		add_null(res);
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) >= (int)ft_strlen(*res) &&
														ft_atoi(*res) < 0)
		add_null(res);
}

void					prepare_str_ex(void)
{
	char				*res_str;

	res_str = ft_strnew(1);
	res_str[0] = '%';
	if (g_com.width[0] != '\0' && ft_atoi(g_com.width) > 1 &&
		input_symb(g_com.flags, '0') && g_com.pr[0] != '\0')
		add_null_in_s(&res_str);
	if (g_com.width[0] != '\0' && ft_atoi(g_com.width) > 1 &&
		input_symb(g_com.flags, '0') && !input_symb(g_com.flags, '-'))
		add_null_in_s(&res_str);
	if (g_com.width[0] != '\0' && ft_atoi(g_com.width) > 1 &&
		g_com.pr[0] == '\0')
		add_esp(&res_str);
	if (g_com.width[0] != '\0' && ft_atoi(g_com.width) > 1 &&
		input_symb(g_com.flags, '0') && g_com.pr[0] == '\0' &&
		!input_symb(g_com.flags, '-'))
		add_null_in_s(&res_str);
	input_text(&res_str, (int)ft_strlen(res_str));
	write(1, g_buffer, g_print);
	g_print_len += g_print;
	g_print = 0;
	ft_strdel(&res_str);
}

void					search_sp_dv(va_list argptr, char ch)
{
	char				*res_str;

	res_str = NULL;
	if (ch == 'U')
		res_str = ft_itoa_u(va_arg(argptr, unsigned long long));
	else if (g_com.size[0] == '\0')
		res_str = ft_itoa(va_arg(argptr, long));
	else if (input_symb(g_com.size, 'z'))
		res_str = ft_itoa((size_t)va_arg(argptr, size_t));
	else if (input_symb(g_com.size, 't'))
		res_str = ft_itoa((ptrdiff_t)va_arg(argptr, ptrdiff_t));
	else if (input_symb(g_com.size, 'j'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned int));
	else if (input_symb(g_com.size, '2'))
		res_str = ft_itoa((long long)va_arg(argptr, long long));
	else if (input_symb(g_com.size, 'l'))
		res_str = ft_itoa((long)va_arg(argptr, long));
	else if (input_symb(g_com.size, 'h'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned int));
	else if (input_symb(g_com.size, '1'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned int));
	res_str = prepare_str(res_str);
	input_text(&res_str, (int)ft_strlen(res_str));
	ft_strdel(&res_str);
}
