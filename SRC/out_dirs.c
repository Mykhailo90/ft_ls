/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:02:28 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/24 18:02:30 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					count_len_word(t_dir_names **ds, int *tab, int x)
{
	t_dir_names			*d;
	int					n;

	d = *ds;
	d->size_name = 0;
	n = 0;
	d->len_dirs = x;
	while (x--)
	{
		if (tab[n] > d->size_name)
			d->size_name = tab[n];
		n++;
	}
	free(tab);
}

t_dir_names				*part_1(DIR **dir, char *path,
						char *name, t_dir_names **ds)
{
	t_dir_names			*d;

	d = *ds;
	if (!(*dir = opendir(path)))
	{
		if (errno == EACCES)
		{
			free(d);
			ft_printf("ft_ls: %s: Permission denied\n", name);
			return (NULL);
		}
		if (errno == ENOENT)
		{
			free(d);
			return (NULL);
		}
	}
	return (d);
}

t_dir_names				*part_2(DIR **dir, t_dir_names **ds, int n,
							struct dirent **dps)
{
	int					*tab;
	t_dir_names			*d;
	struct dirent		*dp;

	dp = *dps;
	d = *ds;
	tab = ft_memalloc(sizeof(int) * n);
	d->dirs = ft_memalloc(sizeof(char *) * n + 1);
	d->dirs[n] = NULL;
	n = 0;
	while ((dp = readdir(*dir)) != NULL)
	{
		if (dp->d_name[0] == '.' && !g_com1.a)
			continue ;
		tab[n] = ft_strlen(dp->d_name);
		d->dirs[n] = ft_strnew(tab[n]);
		ft_strcpy(d->dirs[n], dp->d_name);
		n++;
	}
	count_len_word(&d, tab, n);
	return (d);
}

t_dir_names				*list_dirs(char *path, char *name)
{
	static t_dir_names	*d;
	DIR					*dir;
	struct dirent		*dp;
	int					n;

	dir = NULL;
	d = malloc(sizeof(t_dir_names));
	d = part_1(&dir, path, name, &d);
	if (!d)
		return (NULL);
	n = 0;
	while ((dp = readdir(dir)) != NULL)
		n++;
	rewinddir(dir);
	d = part_2(&dir, &d, n, &dp);
	closedir(dir);
	return (d);
}
