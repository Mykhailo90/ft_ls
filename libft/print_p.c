/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:31:31 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 17:31:32 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				prepare_str_p(char **str, char ch)
{
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) > (int)ft_strlen(*str))
		add_null_before_pr(str);
	add_hesh(str, ch);
	if (g_com.pr[0] == '\0' && g_com.width[0] != '\0' &&
		ft_atoi(g_com.width) > (int)ft_strlen(*str) &&
		input_symb(g_com.flags, '0') && !input_symb(g_com.flags, '-'))
		add_null_after_w(str);
	if (g_com.pr[0] != '\0' && g_com.width[0] != '\0' &&
		ft_atoi(g_com.width) > (int)ft_strlen(*str)
		&& !input_symb(g_com.flags, '-'))
		add_esp(str);
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*str)))
		add_esp(str);
	if (g_com.width[0] != '\0' && input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*str)))
		add_esp(str);
}

void				search_sp_p(unsigned long int tmp, char ch)
{
	char			*res_str;

	res_str = NULL;
	res_str = ft_itoa_base(tmp, ch);
	prepare_str_p(&res_str, ch);
	input_text(&res_str, (int)ft_strlen(res_str));
	ft_strdel(&res_str);
}
