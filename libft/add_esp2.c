/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_esp2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:17:00 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 15:17:01 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_esp_for_cv_end(unsigned char **str)
{
	int					len_ch;
	int					width;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = ft_strlen_uv(*str);
	width = ft_atoi(g_com.width);
	tmp = ft_strnew(width - len_ch);
	while (i < (width - len_ch))
		tmp[i++] = ' ';
	*str = ft_strjoin_uv(*str, (unsigned char *)tmp);
}

void					add_esp_for_s(char **str)
{
	int					len_ch;
	int					width;
	char				*tmp;
	int					i;
	int					flag;

	i = 0;
	len_ch = ft_strlen(*str);
	width = ft_atoi(g_com.width);
	flag = width - len_ch;
	tmp = ft_strnew(width - len_ch);
	if (g_com.pr[0] != '\0' && ft_atoi(g_com.pr) == 0 &&
		g_com.width[0] == '\0' && (*str)[0] != '\0')
		flag++;
	while (i < flag)
		tmp[i++] = ' ';
	*str = (input_symb(g_com.flags, '-')) ?
		ft_strjoin(*str, tmp) : ft_strjoin(tmp, *str);
}

void					add_esp_for_s_end(char **str)
{
	int					len_ch;
	int					width;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = ft_strlen(*str);
	width = ft_atoi(g_com.width);
	tmp = ft_strnew(width - len_ch);
	while (i < (width - len_ch))
		tmp[i++] = ' ';
	*str = ft_strjoin(*str, tmp);
}

void					add_esp_for_cv(unsigned char **str)
{
	int					len_ch;
	int					width;
	char				*tmp;
	int					i;

	i = 0;
	len_ch = ft_strlen_uv(*str);
	width = ft_atoi(g_com.width);
	tmp = ft_strnew(width - len_ch);
	while (i < (width - len_ch))
		tmp[i++] = ' ';
	*str = (input_symb(g_com.flags, '-')) ?
		ft_strjoin_uv(*str, (unsigned char *)tmp) :
		ft_strjoin_uv((unsigned char *)tmp, *str);
}

void					add_esp_one(char **str)
{
	char				*tmp;

	tmp = ft_strnew(1);
	tmp[0] = ' ';
	*str = ft_strjoin(tmp, *str);
}
