/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:43:15 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 19:43:17 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					prepare_str_x2(char **str, char ch)
{
	if (ch == 'p')
		add_hesh(str, ch);
	if (g_com.pr[0] != '\0' && g_com.width[0] != '\0' &&
		ft_atoi(g_com.width) > (int)ft_strlen(*str)
		&& !input_symb(g_com.flags, '-'))
		add_esp(str);
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*str)))
	{
		add_esp(str);
	}
	if (g_com.width[0] != '\0' && input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*str)))
		add_esp(str);
}

void					prepare_str_x(char **str_res, char ch)
{
	char				*str;

	str = *str_res;
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) == 0 &&
		!input_symb(g_com.flags, '#'))
		add_hesh(&str, ch);
	if (g_com.pr[0] == '\0' && g_com.width[0] != '\0' &&
		ft_atoi(g_com.width) > (int)ft_strlen(str) &&
		input_symb(g_com.flags, '0') && !input_symb(g_com.flags, '-'))
	{
		add_null_before_xv(&str, ch);
	}
	if (input_symb(g_com.flags, '#') && (ch == 'o' || ch == 'O'))
		add_hesh_o(&str);
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) > (int)ft_strlen(str))
		add_null(&str);
	if (input_symb(g_com.flags, '#') && (ch == 'x' || ch == 'X') &&
		(str[0] != '0' || str[1] != '\0'))
		add_hesh(&str, ch);
	prepare_str_x2(&str, ch);
	*str_res = str;
}

char					*search_sp_x(unsigned long long n, char ch)
{
	char				*res_str;

	res_str = NULL;
	if (ch == 'O')
		res_str = ft_itoa_base(n, ch);
	else if (g_com.size[0] == '\0')
		res_str = ft_itoa_base((unsigned int)n, ch);
	else if (input_symb(g_com.size, 'z'))
		res_str = ft_itoa_base((size_t)n, ch);
	else if (input_symb(g_com.size, 't'))
		res_str = ft_itoa_base((ptrdiff_t)n, ch);
	else if (input_symb(g_com.size, 'j'))
		res_str = ft_itoa_base((uintmax_t)n, ch);
	else if (input_symb(g_com.size, '2'))
		res_str = ft_itoa_base(n, ch);
	else if (input_symb(g_com.size, 'l'))
		res_str = ft_itoa_base(n, ch);
	else if (input_symb(g_com.size, 'h'))
		res_str = ft_itoa_base((unsigned short int)n, ch);
	else if (input_symb(g_com.size, '1'))
		res_str = ft_itoa_base((unsigned char)n, ch);
	prepare_str_x(&res_str, ch);
	return (res_str);
}
