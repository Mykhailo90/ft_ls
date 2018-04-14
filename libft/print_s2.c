/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:07:32 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 16:07:33 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char			*convert_in_str(wchar_t *tmp)
{
	int					len;
	unsigned char		*res;

	len = size_wt(tmp);
	res = (unsigned char *)ft_strnew(len);
	func_help1(tmp, res, len);
	return (res);
}

void					prepare_str_sv(unsigned char **res_str)
{
	int					len;

	if (g_com.pr[0] != '\0')
		len = ft_atoi(g_com.pr);
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen_uv(*res_str)))
		add_esp_for_cv(res_str);
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		!input_symb(g_com.flags, '-') &&
		ft_atoi(g_com.width) > (int)ft_strlen_uv(*res_str))
		add_null_in_cv(res_str);
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen_uv(*res_str)))
		add_esp_for_cv_end(res_str);
}
