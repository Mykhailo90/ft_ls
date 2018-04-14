/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:57:02 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/29 23:58:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					input_symb(char *str, char ch)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

void				input_text(char **str, int len)
{
	int				i;

	i = 0;
	while (i < len)
	{
		if (g_print < g_size)
		{
			g_buffer[g_print] = (*str)[i];
		}
		else
		{
			g_print_len += g_print;
			write(1, g_buffer, g_print);
			ft_bzero(g_buffer, g_size);
			g_print = 0;
			g_buffer[g_print] = (*str)[i];
		}
		i++;
		g_print++;
	}
}

char				*prepare_str_c(char ch)
{
	char			*res;

	res = ft_strnew(1);
	res[0] = ch;
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > 1))
	{
		add_esp(&res);
	}
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		!input_symb(g_com.flags, '-') && ft_atoi(g_com.width) > 1)
	{
		add_null_in_cvr(&res);
	}
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		input_symb(g_com.flags, '-') && (ft_atoi(g_com.width) > 1))
		add_esp(&res);
	return (res);
}

void				help_search(char **str, int *n)
{
	int				tmp;
	char			*arg;
	char			*result;
	char			*r;

	r = NULL;
	arg = "+-#sSpdDioOuUxXcClhLjzt0123456789. \0";
	*n = 0;
	while (input_symb(arg, (*str)[*n]))
		*n = *n + 1;
	result = prepare_str_c((*str)[*n]);
	tmp = *n;
	if ((*str)[tmp + 1] != '%' && (*str)[tmp + 1] != '\0')
		help_search2(str, n, &r, &result);
	else if ((*str)[tmp + 1] == '%')
	{
		g_error = 0;
		search_specificator(&(*str)[tmp + 2]);
		(*n)++;
	}
	while ((*str)[*n] != '%' && (*str)[*n] != '\0')
		*n = *n + 1;
	input_text(&result, ft_strlen(result));
	ft_strdel(&result);
}

void				search_errors(char **str)
{
	int				i;
	char			*arg;

	arg = "+-#sSpdDioOuUxXcClhLjzt0123456789. \0";
	i = 0;
	while ((*str)[i] != g_com.specificator && (*str)[i] != '\0')
	{
		if (!input_symb(arg, (*str)[i]))
		{
			g_error = 5;
			help_search(str, &i);
		}
		else if ((*str)[i] == '\0')
		{
			input_text(str, i);
			return ;
		}
		if ((*str)[i] != '\0')
			i++;
	}
	if ((*str)[i] == '\0' && g_error != 5)
		g_error = 5;
}
