/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:50:52 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/08 18:50:54 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		search_last_pos(char *str)
{
	int			i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (g_com.width[0] != '\0')
		ft_bzero(g_com.width, 1024);
	ft_strncpy(g_com.width, &str[0], i);
}

void			search_width(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (ft_isdigit(str[i]) && i == 0 && str[i] != '0')
			search_last_pos(&str[i]);
		else if (ft_isdigit(str[i]) && str[i] != '0' && str[i - 1] != '.'
			&& (!ft_isdigit(str[i - 1]) || str[i - 1] == '0'))
			search_last_pos(&str[i]);
		i++;
	}
}
