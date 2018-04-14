/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_null3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:14:51 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/27 14:14:52 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_null_before_xv(char **str, char ch)
{
	t_help				help;

	help.number = ft_atoi(*str);
	help.i = ft_strlen(*str);
	if (input_symb(g_com.flags, '#') && (ch == 'x' || ch == 'X'))
		help.i = help.i + 2;
	if (input_symb(g_com.flags, '#') && (ch == 'o' || ch == 'O'))
		help.i = help.i + 1;
	if (ch == 'p')
		help.i = help.i + 2;
	if (g_com.width[0] != '\0')
		help.n = ft_atoi(g_com.width);
	help.tmp = (help.number < 0 || input_symb(g_com.flags, '+')) ?
		ft_strnew(help.n - help.i + 2) : ft_strnew(help.n - help.i);
	help.n = help.n - help.i;
	help.i = 0;
	full_n(&help.tmp, help.i, help.n);
	*str = ft_strjoin(help.tmp, *str);
}

void					add_null_in_cvr(char **str)
{
	int					len_ch;
	int					w;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = ft_strlen(*str);
	w = ft_atoi(g_com.width);
	tmp = ft_strnew(w - len_ch);
	while (i < (w - len_ch))
		tmp[i++] = '0';
	*str = ft_strjoin(tmp, *str);
}
