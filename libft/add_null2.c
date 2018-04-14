/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_null2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:20:58 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 16:20:59 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_null_after_w(char **str)
{
	char				*tmp;
	int					len;

	len = ft_atoi(g_com.width) - (int)ft_strlen(*str);
	tmp = ft_strnew(len);
	full_n(&tmp, 0, len);
	*str = ft_strjoin(*str, tmp);
}

void					add_null_before_pr(char **str)
{
	char				*tmp;
	int					len;

	len = ft_atoi(g_com.pr) - (int)ft_strlen(*str);
	tmp = ft_strnew(len);
	full_n(&tmp, 0, len);
	*str = ft_strjoin(tmp, *str);
}

void					help_func_u(char **str, t_help *help)
{
	help->n = (g_com.pr[0] != '\0') ? help->n - help->i + 1 : help->n - help->i;
	help->tmp[0] = (ft_atoi(*str) < 0) ? '-' : '+';
	if (*str[0] == '+' || *str[0] == '-')
		*str[0] = '0';
	help->i = 1;
}

void					add_null_in_cv(unsigned char **str)
{
	int					len_ch;
	int					w;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = ft_strlen_uv(*str);
	w = ft_atoi(g_com.width);
	tmp = ft_strnew(w - len_ch);
	while (i < (w - len_ch))
		tmp[i++] = '0';
	*str = ft_strjoin_uv((unsigned char *)tmp, *str);
}

void					add_null_before_u(char **str)
{
	t_help				help;

	help.number = ft_atoi(*str);
	help.i = ft_strlen(*str);
	if (g_com.width[0] != '\0')
		help.n = ft_atoi(g_com.width);
	help.tmp = (input_symb(g_com.flags, '+')) ?
		ft_strnew(help.n - help.i + 2) : ft_strnew(help.n - help.i);
	if (input_symb(g_com.flags, '+'))
		help_func_u(str, &help);
	else
	{
		help.n = help.n - help.i;
		help.i = 0;
	}
	if (input_symb(g_com.flags, ' '))
		help.n = help.n - 1;
	full_n(&help.tmp, help.i, help.n);
	*str = ft_strjoin(help.tmp, *str);
}
