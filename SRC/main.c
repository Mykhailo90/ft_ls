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

void				ft_free(t_dir_names **d)
{
	int				i;
	t_dir_names		*ds;

	i = 0;
	ds = *d;
	if (ds)
	{
		while (ds->dirs[i])
		{
			ft_strdel(&ds->dirs[i]);
			i++;
		}
		if (ds->dirs)
			free(ds->dirs);
	}
}

void				start_list(char **argv, int argc, int i)
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
		if (!(g_com1.R))
			no_r_func(path, name);
		else
			recurse_print(path, name);
		g_com1.fz = 1;
		i++;
	}
}

int 				main(int argc, char **argv)
{
	int 			i;
	t_dir_names 	*d;
	char			*path;
	char			*name;

	path = NULL;
	name = NULL;
	i = search_error(argc, argv);
	if (i == argc)
	{
		path = ft_strdup(".");
		name = ft_strdup(".");
		if (!(g_com1.R))
			d = help(ft_strdup(path), ft_strdup(name));
		else
			recurse_print(ft_strdup(path), ft_strdup(name));
	}
	else
		start_list(argv, argc, i);

	system("leaks ft_ls");
	return (0);
}
