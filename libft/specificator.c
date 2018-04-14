/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:04:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/02/19 20:04:35 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_input_spec(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'd' || ch == 'i' || ch == '%' ||
		ch == 'x' || ch == 'X' || ch == 'u' || ch == 'f' || ch == 'F' ||
		ch == 'e' || ch == 'E' || ch == 'a' || ch == 'A' || ch == 'g' ||
		ch == 'G' || ch == 'n' || ch == 'p' || ch == 'S' || ch == 'D' ||
		ch == 'O' || ch == 'o' || ch == 'U' || ch == 'C')
		return ((int)(ch - '0'));
	return (-1);
}

void	search_specificator(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && is_input_spec(str[i]) == -1)
	{
		i++;
	}
	if (str[i] != '\0')
		g_com.specificator = str[i];
}
