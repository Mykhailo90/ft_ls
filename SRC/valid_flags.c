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

int		is_flag(char ch, t_flags *com)
{
	int i;

	i = 1;
	if (ch == 'l')
		com->l = 1;
	else if (ch == 'R')
		com->R = 1;
	else if (ch == 'a')
		com->a = 1;
	else if (ch == 'r')
		com->r = 1;
	else if (ch == 't')
		com->t = 1;
	else if (ch == '1')
		com->one = 1;
	else
		i = 0;;
	return (i);
}

int		is_flag_arg(char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

int		search_error(int argc, char **argv, t_flags *com)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc && is_flag_arg(argv[i]))
	{
		n = 1;
		while (argv[i][n] != '\0')
		{
			if (!is_flag(argv[i][n], com))
			{
				ft_printf("ft_ls: illegal option -- %c\n", argv[i][n]);
				ft_printf("usage: ft_ls [-Ralrt1] [file ...]\n");
				exit(1);
			}
			n++;
		}
		i++;
	}
	return (i);
}
