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
		return (1);
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
	if (!g_com1.t && !g_com1.r)
		sort_strings((void **)d->ar_roads, (void **)d->dirs,
			d->len_dirs, ft_for_st_sort);
	if (g_com1.t)
		sort_strings((void **)d->ar_roads, (void **)d->dirs,
			d->len_dirs, ft_for_time_sort);
	if (g_com1.r && !g_com1.t)
		sort_strings((void **)d->ar_roads, (void **)d->dirs,
			d->len_dirs, ft_for_st_sort2);
	if (g_com1.r && g_com1.t)
		sort_strings2((void **)d->dirs,
			(void **)d->ar_roads, d->len_dirs);
}

t_dir_names				*help(char *path, char *name)
{
	t_dir_names	*d;

	d = list_dirs(path, name);
	if (d)
	{
		try_sort(d);
		if (g_er_f != 0)
			ft_printf("\n");
		g_er_x = 0;
		g_er_f = 1;
		if (g_com1.many_args == 1)
			ft_printf("%s:\n", path);
		print_dirs(&d);
		d->flag_f = 1;
	}
	if (name)
		ft_strdel(&name);
	if (path)
		ft_strdel(&path);
	return (d);
}
