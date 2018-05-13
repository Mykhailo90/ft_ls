/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:30:53 by msarapii          #+#    #+#             */
/*   Updated: 2018/05/11 11:30:55 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				inicialization(int *i, int *len_c,
												int len_dirs, int columns)
{
	*i = 0;
	if (columns == 0)
		*len_c = len_dirs;
	else
	{
		*len_c = len_dirs / columns;
		if (len_dirs % columns != 0)
			(*len_c)++;
	}
}

int					search_column(int len_symb, t_dir_names **ds)
{
	int				modul;

	modul = len_symb / ((*ds)->size_name + 6);
	return (modul);
}

void				ft_read_link(char *name, struct stat s)
{
	ssize_t			r;
	char			*linkname;

	linkname = (char *)malloc(sizeof(char) * s.st_size);
	linkname[s.st_size] = '\0';
	if (linkname == NULL)
		return ;
	r = readlink(name, linkname, s.st_size + 1);
	if (r >= 1024)
	{
		ft_printf("Link filename too long\n");
		exit(0);
	}
	ft_printf(" -> ");
	ft_printf("%s\n", linkname);
	ft_strdel(&linkname);
	free(linkname);
}

void				print_total(char **dirs)
{
	int				total;

	total = 0;
	while (*dirs)
	{
		lstat(*dirs, &s1);
		total += s1.st_blocks;
		dirs++;
	}
	ft_printf("total %d\n", total);
}

void				print_params(struct stat s)
{
	ft_printf("%c", (s.st_mode & S_IRUSR) ? 'r' : '-');
	ft_printf("%c", (s.st_mode & S_IWUSR) ? 'w' : '-');
	ft_printf("%c", (s.st_mode & S_IXUSR) ? 'x' : '-');
	ft_printf("%c", (s.st_mode & S_IRGRP) ? 'r' : '-');
	ft_printf("%c", (s.st_mode & S_IWGRP) ? 'w' : '-');
	ft_printf("%c", (s.st_mode & S_IXGRP) ? 'x' : '-');
	ft_printf("%c", (s.st_mode & S_IROTH) ? 'r' : '-');
	ft_printf("%c", (s.st_mode & S_IWOTH) ? 'w' : '-');
	ft_printf("%c", (s.st_mode & S_IXOTH) ? 'x' : '-');
}
