/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:42:26 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/25 16:42:28 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						prepare_str4(char **res)
{
	char					*esp;

	if (input_symb(g_com.flags, ' ') && g_com.specificator == 'i' &&
		g_com.width[0] != '\0' && !input_symb(g_com.flags, '+'))
	{
		esp = ft_strnew(1);
		esp[0] = ' ';
		*res = ft_strjoin(esp, *res);
	}
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*res)))
		add_esp(res);
	if (g_com.width[0] != '\0' && input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*res)))
		add_esp(res);
}

void						prepare_str3(char **res)
{
	char					*esp;

	if (input_symb(g_com.flags, ' ') && (ft_atoi(*res) >= 0) &&
		!input_symb(g_com.flags, '+') && g_com.width[0] == '\0')
	{
		esp = ft_strnew(1);
		esp[0] = ' ';
		*res = ft_strjoin(esp, *res);
	}
	if (input_symb(g_com.flags, ' ') && g_com.width[0] != '\0' &&
		((int)ft_strlen(*res) < ft_atoi(g_com.width)) &&
		!input_symb(g_com.flags, '+'))
	{
		esp = ft_strnew(1);
		esp[0] = ' ';
		*res = ft_strjoin(esp, *res);
	}
	prepare_str4(res);
}

void						prepare_str2(char **res)
{
	char					*plus;

	if (g_com.pr[0] == '\0' && g_com.width[0] != '\0' &&
		ft_atoi(g_com.width) > (int)ft_strlen(*res) &&
		input_symb(g_com.flags, '0') && !input_symb(g_com.flags, '-'))
		add_null_before(res);
	if (g_com.pr[0] != '\0' && g_com.width[0] != '\0' && ft_atoi(g_com.width) >
		(int)ft_strlen(*res) && !input_symb(g_com.flags, '-'))
		add_esp(res);
	if (input_symb(g_com.flags, '+') && (ft_atoi(*res) >= 0) &&
		!input_symb(*res, '+') && !input_symb(g_com.flags, '-'))
	{
		plus = ft_strnew(1);
		plus[0] = '+';
		*res = ft_strjoin(plus, *res);
	}
	if (input_symb(g_com.flags, '+') && (ft_atoi(*res) >= 0) &&
		*res[0] != '+' && input_symb(g_com.flags, '-'))
	{
		plus = ft_strnew(1);
		plus[0] = '+';
		*res = ft_strjoin(plus, *res);
	}
	prepare_str3(res);
}

char						*prepare_str(char *str)
{
	char					*res;
	char					*nol;

	nol = NULL;
	res = ft_strnew(ft_strlen(str));
	ft_strcpy(res, str);
	ft_strdel(&str);
	if (g_com.width[0] == '\0' && g_com.pr[0] != '\0' &&
		ft_atoi(g_com.pr) == 0 && ft_atoi(res) == 0)
	{
		nol = ft_strnew(0);
		return (nol);
	}
	if (g_com.width[0] != '\0' && g_com.pr[0] != '\0' &&
		ft_atoi(g_com.pr) == 0 && ft_atoi(res) == 0)
	{
		nol = ft_strnew(0);
		add_esp(&nol);
		return (nol);
	}
	prep_help(&res);
	prepare_str2(&res);
	return (res);
}

void						search_sp_d(va_list argptr)
{
	char					*res_str;

	res_str = NULL;
	if (g_com.size[0] == '\0')
		res_str = ft_itoa(va_arg(argptr, int));
	else if (input_symb(g_com.size, 'z'))
		res_str = ft_itoa((size_t)va_arg(argptr, size_t));
	else if (input_symb(g_com.size, 't'))
		res_str = ft_itoa((ptrdiff_t)va_arg(argptr, ptrdiff_t));
	else if (input_symb(g_com.size, 'j'))
		res_str = ft_itoa(va_arg(argptr, unsigned long));
	else if (input_symb(g_com.size, '2'))
		res_str = ft_itoa((long long)va_arg(argptr, long long));
	else if (input_symb(g_com.size, 'l'))
		res_str = ft_itoa((long)va_arg(argptr, long));
	else if (input_symb(g_com.size, 'h'))
		res_str = ft_itoa((short)va_arg(argptr, int));
	else if (input_symb(g_com.size, '1'))
		res_str = ft_itoa((signed char)va_arg(argptr, int));
	res_str = prepare_str(res_str);
	input_text(&res_str, (int)ft_strlen(res_str));
	ft_strdel(&res_str);
}
