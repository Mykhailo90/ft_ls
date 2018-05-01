/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:02:14 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/17 17:02:16 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int						is_file(char *name)
{
	DIR					*directory;

	directory = opendir(name);
	if (directory != NULL)
	{
		closedir(directory);
		return (0);
	}
	if (errno == ENOTDIR)
	{
		return (1);
	}
	return (-1);
}

int						is_dir(const char *path)
{
	struct stat			s;

	lstat(path, &s);
	if (S_ISDIR(s.st_mode))
		return (1);
	return (0);
}

void					no_r_func(char *path, char *name)
{
	t_dir_names			*d;

	d = help(path, name);
	if (d)
	{
		ft_free(&d);
		free(d);
	}
}

void					try_sort(t_dir_names *d)
{
	if (g_com1.r && g_com1.t)
		sort_strings((void **)d->dirs, d->len_dirs, ft_for_st_sort2);
	else if (g_com1.t)
		sort_strings((void **)d->dirs, d->len_dirs, ft_for_time_sort);
	else if (g_com1.r)
		sort_strings((void **)d->dirs, d->len_dirs, ft_for_st_sort2);
	else
	 	sort_strings((void **)d->dirs, d->len_dirs, ft_for_st_sort);
}

t_dir_names				*help(char *path, char *name)
{
	static t_dir_names	*d;

	d = list_dirs(path, name);
	if (d)
	{
		try_sort(d);
	//	(g_com1.l)
		if (g_com1.fz == 1 && g_er_x == 0 && !g_com1.rb)
			ft_printf("%s:\n", name);
		if (g_com1.fz == 1)
		{
			if (g_er_x != 1)
				ft_printf("\n");
			g_er_x = 0;
			ft_printf("%s:\n", name);
		}
		(g_com1.a) ? print_with_flag_a(&d) : print_without_flags_a(&d);
		d->flag_f = 1;
	}
	else
		ft_printf("%s ", name);
	if (name)
		ft_strdel(&name);
	if (path)
		ft_strdel(&path);
	return (d);
}
