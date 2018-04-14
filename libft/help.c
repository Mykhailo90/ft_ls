/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:39:32 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/29 20:39:33 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				help_func_p(unsigned long long tp, char **nol,
							char **res, char ch)
{
	if (tp == 0 && g_com.pr[0] != '\0' &&
		ft_atoi(g_com.pr) == 0 && !input_symb(g_com.flags, '#'))
	{
		*nol = ft_strnew(1);
		*nol[0] = '0';
		ft_strdel(res);
		*res = prepare_str_s(nol);
		input_text(res, ft_strlen(*res));
		write_help();
		ft_strdel(nol);
	}
	else
		form_p3_help(ch, tp, res);
}

void				write_help(void)
{
	write(1, g_buffer, g_print);
	g_print_len += g_print;
	g_print = 0;
	g_error = 1;
}

void				help_search2(char **str, int *n, char **r, char **result)
{
	int				tmp;

	tmp = *n;
	while ((*str)[*n] != '%' && (*str)[*n] != '\0')
		*n = *n + 1;
	*r = ft_strnew(sizeof(char) * (*n - tmp));
	*r = ft_strncpy(*r, &(*str)[tmp + 1], (*n - tmp - 1));
	*result = ft_strjoin(*result, *r);
}

void				form_p2_help(long *tmp, char ch, va_list argptr)
{
	char			y;

	*tmp = (ch == 'c') ? (long)va_arg(argptr, int) :
							(long)va_arg(argptr, wint_t);
	y = *tmp;
	if ((ch == 'C') && MB_CUR_MAX == 1 && *tmp < 128)
		;
	else if ((ch == 'C') && MB_CUR_MAX == 1 && *tmp < 256)
	{
		write(1, &y, 1);
		g_print_len++;
		g_error = 7;
	}
	else if ((ch == 'C') && MB_CUR_MAX == 1)
		g_error = 6;
}
