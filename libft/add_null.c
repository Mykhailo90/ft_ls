/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 12:14:05 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/25 12:14:06 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_null_before(char **str)
{
	int					num;
	int					len;
	int					w;
	char				*tmp;

	num = ft_atoi(*str);
	len = ft_strlen(*str);
	if (g_com.width[0] != '\0')
		w = ft_atoi(g_com.width);
	tmp = (num < 0 || input_symb(g_com.flags, '+')) ?
		ft_strnew(w - len + 2) : ft_strnew(w - len);
	if (num < 0 || input_symb(g_com.flags, '+'))
		help_func(str, &tmp, &w, &len);
	else
	{
		w = w - len;
		len = 0;
	}
	if (input_symb(g_com.flags, ' '))
		w = w - 1;
	full_n(&tmp, len, w);
	*str = ft_strjoin(tmp, *str);
}

void					full_n(char **tmp, int i, int n)
{
	while (i < n)
	{
		(*tmp)[i] = '0';
		i++;
	}
}

void					help_func(char **str, char **tmp, int *n, int *i)
{
	*n = (g_com.pr[0] != '\0') ? *n - *i + 1 : *n - *i;
	*tmp[0] = (ft_atoi(*str) < 0) ? '-' : '+';
	if (*str[0] == '+' || *str[0] == '-')
		*str[0] = '0';
	*i = 1;
}

void					add_null_in_c(char ch)
{
	int		len;
	int		i;

	i = 0;
	len = ft_atoi(g_com.width);
	while (i++ < len - 1)
		print_symbol('0');
	print_symbol(ch);
}

void					add_null(char **str)
{
	int					num;
	int					len;
	int					pr_len;
	char				*tmp;

	num = ft_atoi(*str);
	len = ft_strlen(*str);
	if (g_com.pr[0] != '\0')
		pr_len = ft_atoi(g_com.pr);
	tmp = (num < 0 || input_symb(g_com.flags, '+')) ?
		ft_strnew(pr_len - len + 1) : ft_strnew(pr_len - len);
	if (num < 0 || input_symb(g_com.flags, '+'))
		help_func(str, &tmp, &pr_len, &len);
	else
	{
		pr_len = pr_len - len;
		len = 0;
	}
	full_n(&tmp, len, pr_len);
	*str = ft_strjoin(tmp, *str);
}
