/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:37:52 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/24 15:37:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					form_p1(va_list argptr)
{
	char				ch;
	unsigned long long	tp;

	ch = g_com.specificator;
	if (ch == 'd' || ch == 'i')
		search_sp_d(argptr);
	else if (ch == 'D' || ch == 'U')
		search_sp_dv(argptr, ch);
	else if (ch == '%')
		prepare_str_ex();
	else if (ch == 's' || ch == 'S')
		search_sp_s(argptr, ch);
	else if (ch == 'u')
		search_sp_u(argptr);
	else if (ch == 'p')
	{
		tp = (unsigned long long)va_arg(argptr, unsigned long int);
		search_sp_p(tp, ch);
	}
}

void					form_p2(va_list argptr)
{
	char				ch;
	long				tmp;
	unsigned char		*res;
	char				*res_str;

	ch = g_com.specificator;
	if (ch == 'c' || ch == 'C')
	{
		form_p2_help(&tmp, ch, argptr);
		if (g_error == 6 || g_error == 7)
			return ;
		res = (unsigned char *)search_sp_c(tmp, ch);
		if (tmp == 0 && g_com.width[0] == '\0')
			print_symbol('\0');
		if (tmp == 0 && g_com.width[0] == '\0' && ch == 'C')
			g_print_len--;
		res_str = (char *)res;
		input_text(&res_str, ft_strlen(res_str));
		ft_strdel(&res_str);
		if (tmp == 0 && g_com.width[0] != '\0')
			g_print++;
		if (tmp > 128)
			write_help();
	}
}

void					form_p3_help(char ch, unsigned long long tp,
									char **res)
{
	if ((ch == 'x' || ch == 'o') && tp == 0 && g_com.pr[0] != '\0' &&
			ft_atoi(g_com.pr) == 0 && g_com.width[0] == '\0' &&
			!input_symb(g_com.flags, '#'))
	{
		g_print--;
		g_error = 2;
	}
	if ((ch == 'x') && tp == 0 && g_com.pr[0] != '\0' &&
			ft_atoi(g_com.pr) == 0 && g_com.width[0] == '\0' &&
			input_symb(g_com.flags, '#'))
	{
		g_error = 2;
	}
	if (g_error != 2)
		input_text(res, (int)ft_strlen(*res));
	write_help();
	ft_strdel(res);
}

void					form_p3(va_list argptr)
{
	char				ch;
	unsigned long long	tp;
	char				*res;
	char				*nol;
	int					i;

	i = 0;
	ch = g_com.specificator;
	res = NULL;
	if (ch == 'x' || ch == 'X' || ch == 'O' || ch == 'o')
	{
		tp = va_arg(argptr, unsigned long long);
		res = search_sp_x(tp, ch);
		help_func_p(tp, &nol, &res, ch);
	}
}

void					form_string(va_list argptr, char *str)
{
	char				ch;

	search_errors(&str);
	ch = g_com.specificator;
	if (g_error != 5)
	{
		form_p1(argptr);
		form_p2(argptr);
		if (g_error == 6 || g_error == 7)
			return ;
		form_p3(argptr);
		if (g_error == 2)
			return ;
		if (g_error == 4)
			g_print_len++;
	}
}
