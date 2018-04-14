/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:08:37 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 18:08:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					prepare_str_cv(unsigned char **str)
{
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen_uv(*str)))
		add_esp_for_cv(str);
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		!input_symb(g_com.flags, '-') &&
		ft_atoi(g_com.width) > (int)ft_strlen_uv(*str))
	{
		add_null_in_cv(str);
	}
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen_uv(*str)))
		add_esp_for_cv_end(str);
}

void					prepare_str_cvl(char **str)
{
	int					j;

	j = 1;
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*str)))
		add_esp(str);
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		!input_symb(g_com.flags, '-') &&
		ft_atoi(g_com.width) > (int)ft_strlen(*str))
	{
		if ((*str)[0] == '0')
		{
			add_null_in_c('\0');
			g_print_len--;
		}
		else
			while (j++ < ft_atoi(g_com.width))
				print_symbol('0');
	}
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*str)))
		add_esp_for_cv_end((unsigned char **)str);
}

unsigned char			*search_sp_c(long n, char s)
{
	char				*res_str;
	unsigned char		*str;
	wchar_t				ch[2];

	str = NULL;
	res_str = NULL;
	if (g_com.size[0] == '\0' && s != 'C')
	{
		res_str = ft_strnew(1);
		res_str[0] = (n != 0) ? (char)n : '\0';
	}
	else if (s == 'C' || input_symb(g_com.size, 'l'))
	{
		if (n == 0)
			print_symbol('\0');
		ch[0] = n;
		ch[1] = '\0';
		str = convert_in_str(ch);
		prepare_str_cv(&str);
		return ((unsigned char *)str);
	}
	prepare_str_cvl(&res_str);
	return ((unsigned char *)res_str);
}
