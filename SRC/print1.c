/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:08:53 by msarapii          #+#    #+#             */
/*   Updated: 2018/05/11 18:08:54 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void						print1_with_flag_a(t_dir_names **ds)
{
	int						i;
	int						l;
	t_dir_names				*d;

	i = 0;
	d = *ds;
	l = d->len_dirs;
	while (i < l)
	{
		ft_printf("%s\n", d->dirs[i]);
		i++;
	}
}

void						print1_without_flags_a(t_dir_names **ds)
{
	int						i;
	int						l;
	t_dir_names				*d;

	i = 0;
	d = *ds;
	l = d->len_dirs;
	while (i < l)
	{
		if (d->dirs[i][0] != '.')
			ft_printf("%s\n", d->dirs[i]);
		i++;
	}
}

void						print_i_with_flag_a(t_dir_names **ds,
											int columns, int len_w)
{
	int						i;
	int						x;
	int						len_c;
	int						tmp;

	inicialization(&i, &len_c, (*ds)->len_dirs, columns);
	while (i < len_c)
	{
		lstat((*ds)->ar_roads[i], &s1);
		ft_printf("%-8ld%-*s", s1.st_ino, len_w, (*ds)->dirs[i]);
		tmp = len_c;
		x = columns;
		while (x)
		{
			if ((i + tmp) < (*ds)->len_dirs)
			{
				lstat((*ds)->ar_roads[i], &s1);
				ft_printf("%-8ld%-*s", s1.st_ino, len_w, (*ds)->dirs[i + tmp]);
				tmp += len_c;
			}
			x--;
		}
		ft_printf("\n");
		i++;
	}
}

static void					h3(int i, int tmp, t_dir_names **ds, int len_w)
{
	if ((*ds)->dirs[i + tmp][0] != '.')
	{
		lstat((*ds)->ar_roads[i], &s1);
		ft_printf("%-8ld%-*s", s1.st_ino, len_w,
					(*ds)->dirs[i + tmp]);
	}
}

void						print_i_without_flags_a(t_dir_names **ds,
											int columns, int len_w)
{
	t_ar					y;

	inicialization(&y.i, &y.len_c, (*ds)->len_dirs, columns);
	while (y.i < y.len_c)
	{
		if ((*ds)->dirs[y.i][0] != '.')
		{
			lstat((*ds)->ar_roads[y.i], &s1);
			ft_printf("%-8ld%-*s", s1.st_ino, len_w, (*ds)->dirs[y.i]);
		}
		y.tmp = y.len_c;
		y.x = columns;
		while (y.x--)
		{
			if ((y.i + y.tmp) < (*ds)->len_dirs)
			{
				h3(y.i, y.tmp, ds, len_w);
				y.tmp += y.len_c;
			}
		}
		ft_printf("\n");
		y.i++;
	}
}
