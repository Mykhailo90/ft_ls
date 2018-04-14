/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:46:52 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 17:46:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					add_hesh(char **res, char ch)
{
	char				tmp[3];
	char				*temp;

	tmp[0] = '0';
	tmp[2] = '\0';
	tmp[1] = (ch == 'x' || ch == 'p') ? 'x' : 'X';
	if (ch == 'p' && (*res)[0] == '0' && (*res)[1] == '\0' &&
		g_com.pr[0] != '\0' && ft_atoi(g_com.pr) == 0)
	{
		temp = ft_strnew(2);
		temp[0] = '0';
		temp[1] = 'x';
		ft_strdel(res);
		*res = temp;
		return ;
	}
	temp = ft_strnew(ft_strlen(tmp));
	ft_strcpy(temp, tmp);
	*res = ft_strjoin(temp, *res);
}

void					add_hesh_o(char **res)
{
	char				*tmp;

	if ((*res)[0] != '0')
	{
		tmp = ft_strnew(1);
		tmp[0] = '0';
		*res = ft_strjoin(tmp, *res);
	}
}
