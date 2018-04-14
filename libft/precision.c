/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:16:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/27 16:16:34 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_pr(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		if (str[i] == '.')
			g_com.pr[0] = '0';
		if (str[i] == '.' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
		{
			while (ft_isdigit(str[++i]))
				n++;
			if (g_com.pr[0] != '\0')
				ft_bzero(g_com.pr, 1024);
			ft_strncpy(g_com.pr, &str[i - n], n);
		}
		i++;
	}
}
