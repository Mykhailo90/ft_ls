/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 12:42:33 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/14 12:44:49 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			pt_link(char *path)
{
	lstat(path, &s2);
	print_type(s2);
	print_params(s2);
	ft_count_link(s2);
	ft_printf(" \t");
	print_pwname(s2);
	ft_printf(" \t");
	print_year(s2);
	ft_printf(" ");
	if (S_ISCHR(s2.st_mode) || S_ISBLK(s2.st_mode))
		minor_major(s2);
	else
		print_size(s2);
	ft_printf(" ");
	print_t(s2);
	ft_printf(" \t");
	if (S_ISLNK(s2.st_mode))
	{
		ft_printf("%s", path);
		ft_read_link(path, s2);
	}
	else
		ft_printf("%s\n", path);
}

static void			h1(char *path)
{
	if (g_er_f == 1)
		ft_printf("\n");
	ft_printf("%s\n", path);
	g_er_f = 1;
}

static void			h2(char *path)
{
	if (g_er_f)
		ft_printf("\n");
	pt_link(path);
}

static void			start_list(char **argv, int argc, int i)
{
	char			*path;
	char			*name;

	sort_args(argv, argc, i);
	if (search_error_names(i, argc, argv))
		g_er_x = 1;
	while (i < argc)
	{
		name = ft_strdup(argv[i]);
		path = ft_strdup(argv[i]);
		if (!is_dir(path) && !(g_com1.l) && lstat(path, &s1) != -1)
			h1(path);
		else if (!is_dir(path) && (g_com1.l) && lstat(path, &s1) != -1)
			h2(path);
		else if (!(g_com1.rb) && lstat(path, &s1) != -1)
			no_r_func(path, name);
		else if (stat(path, &s1) != -1)
			recurse_print(path, name);
		g_com1.fz = 1;
		i++;
	}
}

int					main(int argc, char **argv)
{
	int				i;
	t_dir_names		*d;
	char			*path;
	char			*name;

	path = NULL;
	name = NULL;
	i = search_error(argc, argv);
	g_com1.l = (g_com1.g == 1) ? 1 : g_com1.l;
	if (i == argc)
	{
		path = ft_strdup(".");
		name = ft_strdup(".");
		if (!(g_com1.rb))
			d = help(ft_strdup(path), ft_strdup(name));
		else
			recurse_print(ft_strdup(path), ft_strdup(name));
	}
	else
	{
		if (i + 1 != argc)
			g_com1.many_args = 1;
		start_list(argv, argc, i);
	}
	return (0);
}
