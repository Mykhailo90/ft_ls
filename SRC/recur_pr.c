/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_pr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:34:12 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/24 18:34:13 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				recurse_print2(t_dir_names **ds, int i, char *path)
{
	t_dir_names 	*d;
	char 			*tmp;
	char			*name;
	char 			*tmp2;

	d = *ds;
	tmp = NULL;
	tmp2 = NULL;
	if (strcmp(d->dirs[i], ".") == 0 || strcmp(d->dirs[i], "..") == 0)
		return ;
	tmp = ft_strjoin(ft_strdup("/"), ft_strdup(d->dirs[i]));
	name = ft_strdup(d->dirs[i]);
	tmp2 = ft_strdup(path);
	tmp = ft_strjoin(tmp2, tmp);
	if (is_dir(tmp))
	{
		printf("\n%s:\n", tmp);
		recurse_print(ft_strdup(tmp), ft_strdup(name));
	}
	ft_strdel(&name);
	ft_strdel(&tmp);
}

void				recurse_print(char *path, char *name)
{
	int 			i;
	t_dir_names 	*d;
	
	d = NULL;
	
	if (is_dir(path))
		d = help(ft_strdup(path), ft_strdup(name));
	if (d)
	{
		i = 0;
		int z = d->len_dirs;
		while (i < z)
		{
			recurse_print2(&d, i, path);
			i++;		
		}
		ft_free(&d);
		free(d);
	}
	if (name)
	 	ft_strdel(&name);
	if (path)
	 	ft_strdel(&path);
}