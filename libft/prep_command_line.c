/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_g_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:17:37 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/27 16:17:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				set_list_null(void)
{
	ft_bzero(g_com.size, 9);
	ft_bzero(g_com.pr, 1024);
	ft_bzero(g_com.width, 1024);
	ft_bzero(g_com.flags, 6);
}

void				read_com_str(char *str)
{
	set_list_null();
	search_specificator(str);
	search_flags(str);
	search_width(str);
	search_pr(str);
	search_size(str);
}
