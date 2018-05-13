/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:26:53 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/14 16:26:55 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			is_flag(char ch)
{
	int				i;

	i = 1;
	if (ch == 'l')
		g_com1.l = 1;
	else if (ch == 'R')
		g_com1.rb = 1;
	else if (ch == 'a')
		g_com1.a = 1;
	else if (ch == 'r')
		g_com1.r = 1;
	else if (ch == 't')
		g_com1.t = 1;
	else if (ch == '1')
		g_com1.one = 1;
	else if (ch == 'i')
		g_com1.i = 1;
	else if (ch == 'f')
		g_com1.a = 1;
	else if (ch == 'g')
		g_com1.g = 1;
	else
		i = 0;
	return (i);
}

static int			is_flag_arg(char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

int					search_error(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc && is_flag_arg(argv[i]))
	{
		n = 1;
		while (argv[i][n] != '\0')
		{
			if (!is_flag(argv[i][n]))
			{
				ft_printf("ft_ls: illegal option -- %c\n", argv[i][n]);
				ft_printf("usage: ft_ls [-Ralrti1fg] [file ...]\n");
				exit(1);
			}
			n++;
		}
		i++;
	}
	return (i);
}

int					search_error_names(int x, int argc, char **argv)
{
	int				tmp;
	struct stat		s;

	tmp = 0;
	while (x < argc)
	{
		if (stat(argv[x], &s) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", argv[x]);
			g_er_f = 1;
			tmp++;
		}
		x++;
	}
	return ((tmp != 0) ? 1 : 0);
}
