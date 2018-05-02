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

void					print_l_flag_a(t_dir_names **ds)
{
	int				i;
	int 			len_str;
	t_dir_names		*d;

	d = *ds;
	i = 0;
	len_str = d->len_dirs;

	print_total(d->ar_roads);

	while (len_str != 0)
	{	
		print_type(d->ar_roads[i]);
		print_fin_param(d->ar_roads[i]);
		ft_strdel(&(d)->ar_roads[i]);
		ft_printf(" ");
		ft_printf("%s\n", d->dirs[i]);
		i++;
		len_str--;
	}
	ft_printf("\n");
	free(d->ar_roads);
}

void					print_l_no_flags_a(t_dir_names **ds)
{
	int				i;
	int				len_str;
	t_dir_names		*d;
    d = *ds;
	i = 0;
	len_str = d->len_dirs;
	
	print_total(d->ar_roads);

	while (len_str != 0)
	{
		if (d->dirs[i][0] != '.')
		{
			print_type(d->ar_roads[i]);
			print_fin_param(d->ar_roads[i]);
			ft_strdel(&(d)->ar_roads[i]);
			ft_printf(" ");
			ft_printf("%s\n", d->dirs[i]);
		}
		i++;
		len_str--;
	}
	ft_printf("\n");
	free(d->ar_roads);
}

void				inicialization(int *i, int *len_c,
												int len_dirs, int columns)
{
	*i = 0;
	*len_c = len_dirs / columns;
	if (len_dirs % columns != 0)
		(*len_c)++;
}

void				print_with_flag_a(t_dir_names **ds,
											int columns, int len_w)
{
	int				i;
	int				x;
	int				len_c;
	int				tmp;

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

void				print_without_flags_a(t_dir_names **ds,
											int columns, int len_w)
{
	int				i;
	int				x;
	int				len_c;
	int				tmp;
	
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

int					search_column(int len_symb, t_dir_names **ds)
{
	int				modul; 

	modul = 1;
	if (len_symb > 25 && len_symb < 50)
		modul = 2;
	else if (len_symb < 75)
		modul = 3;
	else if (len_symb < 100)
		modul = 4;
	else if (len_symb < 150)
		modul = 5;
	else if (len_symb < 200)
		modul = 6;
	else if (len_symb < 230)
		modul = 7;
	else if (len_symb >= 230)
		modul = 8;
	while (len_symb < (((*ds)->size_name + 6) * modul))
		modul--;
	if (modul == 0)
		modul++;
	return (modul);
}

void				print_dirs(t_dir_names **ds)
{
	t_dir_names		*d;
	struct winsize 	w;
	int				len_symb;
	int				columns;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    len_symb = w.ws_col;
    columns = (g_com1.l) ? 1 : search_column(len_symb, ds);
	d = *ds;
	if (!g_com1.l)
		(g_com1.a) ? print_with_flag_a(&d, columns, d->size_name + 6) :
					print_without_flags_a(&d, columns, d->size_name + 6);
	else
		(g_com1.a) ? print_l_flag_a(&d) :
					print_l_no_flags_a(&d);
}






