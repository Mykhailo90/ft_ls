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
/*
void					list_dirs_mod(char *path, t_dir_names *d)
{
	DIR 			*dir;
	struct dirent	*dp;
	int 			n;
	int				i;

	dir = opendir(path);
	n = 0;
	i = 0;
	while ((dp = readdir(dir)) != 0)
	{
		n++;
	}
	rewinddir(dir);
	free_old(d);
	d->dirs = malloc(sizeof(char *) * n);
	d->dirs[n] = NULL;
	while ((dp = readdir(dir)) != 0)
	{
		d->dirs[i] = ft_strnew(ft_strlen(dp->d_name));
		ft_strcpy(d->dirs[i], dp->d_name);
		i++;
	}
	closedir(dir);
}
*/

void				count_len_word(t_dir_names **ds, int *tab, int x)
{
	t_dir_names		*d;
	int				n;

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

t_dir_names			*list_dirs(char *path, t_flags *com, char *name)
{
	static t_dir_names 	*d;
	DIR 			*dir;
	struct dirent	*dp;
	int 			n;
	int				*tab;


	d = malloc(sizeof(t_dir_names));
	if (!(dir = opendir(path)))
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
	n = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		n++;
	}
	rewinddir(dir);

	tab = malloc(sizeof(int) * n);
	d->dirs = malloc(sizeof(char *) * n);
	n = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] == '.' && !com->a)
			continue ;
		tab[n] = ft_strlen(dp->d_name);
		d->dirs[n] = ft_strnew(tab[n]);
		ft_strcpy(d->dirs[n], dp->d_name);
		n++;
	}
	count_len_word(&d, tab, n);
	closedir(dir);
	return (d);
}

void				recurse_print(t_flags *com, char *path, char *name)
{
	int 			i;
	char 			*tmp;
	char 			*tmp2;
	t_dir_names 	*d;
	
	//if (d->flag_f == 0)
	// ft_printf("in rec >>\n");
	// ft_printf("in rec >> %s\n", path);
	d = NULL;
	tmp = NULL;
	tmp2 = NULL;
	
	
	if (is_dir(path))
		d = help(ft_strdup(path), com, ft_strdup(name));
//system("leaks ft_ls");
	if (d)
	{
		i = 0;
		int z = d->len_dirs;
	//printf("!!!%s\n", d->dirs[i]);
		while (i < z)
		{
			if (strcmp(d->dirs[i], ".") == 0 || strcmp(d->dirs[i], "..") == 0)
			{
				i++;
				continue ;
			}
		//printf(">>>%d<<<\n", i);
			tmp = ft_strjoin(ft_strdup("/"), ft_strdup(d->dirs[i]));
			if (name)
				ft_strdel(&name);
			name = ft_strdup(d->dirs[i]);
			tmp2 = ft_strdup(path);
			tmp = ft_strjoin(tmp2, tmp);
			if (is_dir(tmp))
			{
				printf("\n%s:\n", tmp);
			//help_mod(ft_strdup(tmp), d);
				recurse_print(com, ft_strdup(tmp), ft_strdup(name));
			//printf(">>>%s\n", tmp);
	//		printf(">>>%d<<<\n", z);
			//ft_strdel(&tmp);
			//help(ft_strdup(path), d);
			// list_dirs("path", d);
			// sort_strings(d);
			// print_without_flags_a(d);
			}
			ft_strdel(&name);
			ft_strdel(&tmp);
		i++;		
		}
		 if(d)
		 {
		 	ft_free(&d);
			free(d);
		 }
	}
	if (name)
	 	ft_strdel(&name);
	if (path)
	 	ft_strdel(&path);
}
/*
void				output_errors(char **ar)
{
	int				n;
	n = 0;

	n = 0;
	while (ar[n])
	{

		n++;
	}
	ar = sort_errors(ar, n);
	n = 0;
	while (ar[n])
	{
		ft_printf("ft_ls: %s: No such file or directory\n", ar[n]);
		n++;
	}
}

void				print_er(int x, int argc, char **argv, char **ar)
{
	//char 			*path;
	int				tmp;
	//DIR 			*dir;
	//char			*name;
	struct stat 	s;

	tmp = 0;
	while (x < argc)
	{		
		if (stat(argv[x], &s) == -1)
		{
			ar[tmp] = ft_strdup(argv[x]);
	 			tmp++;
		}
	 	// 	name = ft_strdup(argv[x]);
	 	// 	path = ft_strjoin(ft_strdup("./"), ft_strdup(argv[x]));
	 	// 	if (!(dir = opendir(path)) && errno == ENOENT)
	 	// 	{
	 	// 		ar[tmp] = ft_strdup(name);
	 	// 		tmp++;
	 	// 	}
			// if (dir)
			// 	closedir(dir);
			x++;
	}
	output_errors(ar);
}
*/
int				search_error_names(int x, int argc, char **argv)
{
	int				tmp;
	struct stat 	s;

	tmp = 0;
	while (x < argc)
	{		
		if (stat(argv[x], &s) == -1)
		{
			ft_printf("ft_ls: %s: No such file or directory\n", argv[x]);
			tmp++;
		}
		x++;
	}
	return ((tmp != 0) ? 1 : 0);
}

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

int 				main(int argc, char **argv)
{
	int 			i;
	int				x;
	static t_flags 	com;
	t_dir_names 	*d;
	char			*path;
	char			*name;

	path = NULL;
	name = NULL;
	i = search_error(argc, argv, &com);
	x = i;
	if (i == argc)
	{
		path = ft_strdup(".");
		name = ft_strdup(".");

		if (!com.R){
		
			d = help(ft_strdup(path), &com, ft_strdup(name));
			
		}
		else
		{
			
			recurse_print(&com, ft_strdup(path), ft_strdup(name));
		}
	}
	else
	{
		sort_args(argv, argc, i);
		if (search_error_names(x, argc, argv))
			g_er_x = 1;
		//sort_args(argv, argc, i);
		while (i < argc)
	 	{
	 		
	 		name = ft_strdup(argv[i]);
	 		// path = ft_strjoin(ft_strdup("./"), ft_strdup(argv[i]));
	 		path = ft_strdup(argv[i]);
	 		if (!com.R){
	 			// if (com.fz != 1)
	 			// 	ft_printf("%s:\n", name);
	 			d = help(path, &com, name);
	 			if (d)
	 			{
	 				ft_free(&d);
	 				free(d);
	 			}
	 			//ft_strdel(&name);
	 		}
	 		else
	 			recurse_print(&com, ft_strdup(path), ft_strdup(name));
	 		com.fz = 1;
	 		i++;
	 	}
	}

	system("leaks ft_ls");
	return (0);
}
