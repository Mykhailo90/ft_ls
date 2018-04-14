/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:47:07 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 16:47:08 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				prepare_str_u2(char **res)
{
	if (g_com.pr[0] != '\0' && g_com.width[0] != '\0' && ft_atoi(g_com.width) >
		(int)ft_strlen(*res) && !input_symb(g_com.flags, '-'))
		add_esp(res);
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*res)))
		add_esp(res);
	if (g_com.width[0] != '\0' && input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*res)))
		add_esp(res);
}

void				prepare_str_u(char **str)
{
	char			*res;

	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) == 0)
	{
		ft_strdel(str);
		res = ft_strnew(0);
		*str = res;
		return ;
	}
	res = ft_strnew(ft_strlen(*str));
	ft_strcpy(res, *str);
	ft_strdel(str);
	if (g_com.pr[0] == '\0' && g_com.width[0] != '\0' &&
		ft_atoi(g_com.width) > (int)ft_strlen(res) &&
		input_symb(g_com.flags, '0') && !input_symb(g_com.flags, '-'))
		add_null_before_u(&res);
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) > (int)ft_strlen(res))
		add_null(&res);
	prepare_str_u2(&res);
	*str = res;
}

void				search_sp_u(va_list argptr)
{
	char			*res_str;

	res_str = NULL;
	if (g_com.size[0] == '\0')
		res_str = ft_itoa(va_arg(argptr, unsigned int));
	else if (input_symb(g_com.size, 'z'))
		res_str = ft_itoa_u(va_arg(argptr, size_t));
	else if (input_symb(g_com.size, 't'))
		res_str = ft_itoa((unsigned long long)va_arg(argptr, ptrdiff_t));
	else if (input_symb(g_com.size, 'j'))
		res_str = ft_itoa_u((intmax_t)va_arg(argptr, uintmax_t));
	else if (input_symb(g_com.size, '2'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned long long));
	else if (input_symb(g_com.size, 'l'))
		res_str = ft_itoa_u(va_arg(argptr, unsigned long));
	else if (input_symb(g_com.size, 'h'))
		res_str = ft_itoa((unsigned short)va_arg(argptr, int));
	else if (input_symb(g_com.size, '1'))
		res_str = ft_itoa((unsigned char)va_arg(argptr, int));
	prepare_str_u(&res_str);
	input_text(&res_str, (int)ft_strlen(res_str));
	ft_strdel(&res_str);
}
