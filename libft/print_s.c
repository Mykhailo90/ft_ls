/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:43:01 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 14:43:03 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					size_wt(wchar_t *tmp)
{
	int				i;
	int				n;

	i = 0;
	n = 0;
	while (tmp[i])
	{
		if (tmp[i] <= 127)
			n += 1;
		else if (tmp[i] <= 2047)
			n += 2;
		else if (tmp[i] <= 65535)
			n += 3;
		else if (tmp[i] <= 1114111)
			n += 4;
		i++;
	}
	return (n);
}

unsigned char		*search_wt_str(va_list argptr)
{
	wchar_t			*tmp;
	unsigned char	*res_str;
	char			*nn;

	nn = "(null)";
	res_str = NULL;
	tmp = va_arg(argptr, wchar_t *);
	if (tmp == NULL)
	{
		res_str = (unsigned char *)ft_strnew(ft_strlen(nn));
		ft_strcpy_uv(res_str, (unsigned char *)nn);
	}
	else if (g_com.pr[0] != '\0' && (ft_atoi(g_com.pr) < size_wt(tmp)))
		res_str = convert_in_str1(tmp, ft_atoi(g_com.pr));
	else
		res_str = convert_in_str(tmp);
	return (res_str);
}

void				prepare_str_s2(char **res, char **tmp)
{
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) < (int)ft_strlen(*res))
	{
		*tmp = ft_strnew(ft_atoi(g_com.pr));
		ft_strncpy(*tmp, *res, ft_atoi(g_com.pr));
		ft_strdel(res);
		*res = *tmp;
	}
	if (g_com.width[0] != '\0' && !input_symb(g_com.flags, '0') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*res)))
	{
		add_esp_for_s(res);
	}
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		!input_symb(g_com.flags, '-') &&
		ft_atoi(g_com.width) > (int)ft_strlen(*res))
		add_null_in_s(res);
	else if (g_com.width[0] != '\0' && input_symb(g_com.flags, '0') &&
		input_symb(g_com.flags, '-') &&
		(ft_atoi(g_com.width) > (int)ft_strlen(*res)))
		add_esp_for_s_end(res);
}

char				*prepare_str_s(char **res_str)
{
	char			*res;
	char			*tmp;
	char			*nn;

	nn = "(null)";
	tmp = NULL;
	if (*res_str && (*res_str)[0] == '0' && g_com.pr[0] != '\0' &&
		ft_atoi(g_com.pr) == 0)
	{
		res = ft_strnew(0);
	}
	else if (*res_str == NULL)
	{
		res = ft_strnew(ft_strlen(nn));
		ft_strcpy(res, nn);
	}
	else
	{
		res = ft_strdup(*res_str);
	}
	prepare_str_s2(&res, &tmp);
	return (res);
}

void				search_sp_s(va_list argptr, char ch)
{
	char			*res_str;
	unsigned char	*res;

	res_str = NULL;
	res = NULL;
	if (g_com.size[0] == '\0' && ch != 'S')
	{
		res_str = va_arg(argptr, char *);
	}
	else if (ch == 'S' || (g_com.size[0] != '\0' &&
								input_symb(g_com.size, 'l')))
	{
		res = search_wt_str(argptr);
		prepare_str_sv(&res);
		res_str = (char *)res;
		input_text(&res_str, (int)ft_strlen_uv(res));
		ft_strdel_uv(&res);
		return ;
	}
	res_str = prepare_str_s(&res_str);
	input_text(&res_str, (int)ft_strlen(res_str));
	ft_strdel(&res_str);
}
