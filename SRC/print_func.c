/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:09:09 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/17 17:09:11 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void						print_l_flag_a(t_dir_names **ds)
{
	int						i;
	int						len_str;
	t_dir_names				*d;

	d = *ds;
	i = 0;
	len_str = d->len_dirs;
	print_total(d->ar_roads);
	while (len_str != 0)
	{
		lstat(d->ar_roads[i], &s1);
		print_type(s1);
		print_fin_param(s1);
		ft_printf(" ");
		if (S_ISLNK(s1.st_mode))
		{
			ft_printf("%s", d->dirs[i]);
			ft_read_link(d->ar_roads[i], s1);
		}
		else
			ft_printf("%s\n", d->dirs[i]);
		i++;
		len_str--;
	}
	ft_printf("\n");
}

void						print_l_no_flags_a(t_dir_names **d)
{
	int						i;
	int						len_str;

	i = 0;
	len_str = (*d)->len_dirs;
	print_total((*d)->ar_roads);
	while (len_str--)
	{
		if ((*d)->dirs[i][0] != '.')
		{
			lstat((*d)->ar_roads[i], &s1);
			print_type(s1);
			print_fin_param(s1);
			ft_printf(" ");
			if (S_ISLNK(s1.st_mode))
			{
				ft_printf("%s", (*d)->dirs[i]);
				ft_read_link((*d)->ar_roads[i], s1);
			}
			else
				ft_printf("%s\n", (*d)->dirs[i]);
		}
		i++;
	}
	ft_printf("\n");
}

void						print_with_flag_a(t_dir_names **ds,
											int columns, int len_w)
{
	int						i;
	int						x;
	int						len_c;
	int						tmp;

	inicialization(&i, &len_c, (*ds)->len_dirs, columns);
	while (i < len_c)
	{
		ft_printf("%-*s", len_w, (*ds)->dirs[i]);
		tmp = len_c;
		x = columns;
		while (x)
		{
			if ((i + tmp) < (*ds)->len_dirs)
			{
				ft_printf("%-*s", len_w, (*ds)->dirs[i + tmp]);
				tmp += len_c;
			}
			x--;
		}
		ft_printf("\n");
		i++;
	}
}

void						print_without_flags_a(t_dir_names **ds,
											int columns, int len_w)
{
	int						i;
	int						x;
	int						len_c;
	int						tmp;

	inicialization(&i, &len_c, (*ds)->len_dirs, columns);
	while (i < len_c)
	{
		if ((*ds)->dirs[i][0] != '.')
			ft_printf("%-*s", len_w, (*ds)->dirs[i]);
		tmp = len_c;
		x = columns;
		while (x)
		{
			if ((i + tmp) < (*ds)->len_dirs)
			{
				if ((*ds)->dirs[i + tmp][0] != '.')
					ft_printf("%-*s", len_w, (*ds)->dirs[i + tmp]);
				tmp += len_c;
			}
			x--;
		}
		ft_printf("\n");
		i++;
	}
}

void						print_dirs(t_dir_names **ds)
{
	t_dir_names				*d;
	struct winsize			w;
	int						len_symb;
	int						columns;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	len_symb = w.ws_col;
	columns = (g_com1.l) ? 1 : search_column(len_symb, ds);
	d = *ds;
	if (g_com1.i == 1)
		(g_com1.a) ? print_i_with_flag_a(&d, columns, d->size_name + 6) :
					print_i_without_flags_a(&d, columns, d->size_name + 6);
	else if (!g_com1.l && !g_com1.one)
		(g_com1.a) ? print_with_flag_a(&d, columns, d->size_name + 6) :
					print_without_flags_a(&d, columns, d->size_name + 6);
	else if (!g_com1.l && g_com1.one == 1)
		(g_com1.a) ? print1_with_flag_a(&d) :
					print1_without_flags_a(&d);
	else
		(g_com1.a) ? print_l_flag_a(&d) :
					print_l_no_flags_a(&d);
}
