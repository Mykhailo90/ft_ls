/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:46:01 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/25 17:46:03 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_pwname(char *name)
{
	stat(name, &s1);
	if ((pwd = getpwuid(s1.st_uid)) != NULL)
		ft_printf("%s ", pwd->pw_name);
}

void	print_year(char *name)
{
	stat(name, &s1);
	if ((grp = getgrgid(s1.st_gid)) != NULL)
		ft_printf("%s  ", grp->gr_name);
}

void	print_size(char *name)
{
	stat(name, &s1);
	ft_printf("%5d ", s1.st_size);
}

void	print_t(char *name)
{
	char	*t;
	int		i;
	int		len;

	i = 0;
	len = 0;
	stat(name, &s1);
	t = ctime(&s1.st_mtime);
	//t = ft_strdup(&s1.st_mtime);
	len = ft_strlen(t);
	while (t[len] != ' ')
		len--;
	while (t[i] != ' ')
		i++;
	len = len - 3;
	while (i < len)
	{
		ft_printf("%c", t[i]);
		i++;
	}
}

void	print_fin_time(char *time)
{
	char	*s;
	int		i;
	char	**ar;

	i = 0;
	s = time;
	ar = ft_strsplit(s, ':');
	ft_printf("%s:%s", *&ar[0], *&ar[1]);
	while (ar[i] != NULL)
	{
		ft_strdel(&ar[i]);
		i++;
	}
}


void	print_total(char **dirs)
{
	int		total;

	total = 0;
	while (*dirs)
	{
		stat(*dirs, &s1);
		total += s1.st_blocks;
		dirs++;
	}
	ft_printf("total %d\n", total);
}


void	print_params(char *name)
{
	lstat(name, &s1);
	ft_printf("%c", (s1.st_mode & S_IRUSR) ? 'r' : '-');
	ft_printf("%c", (s1.st_mode & S_IWUSR) ? 'w' : '-');
	ft_printf("%c", (s1.st_mode & S_IXUSR) ? 'x' : '-');
	ft_printf("%c", (s1.st_mode & S_IRGRP) ? 'r' : '-');
	ft_printf("%c", (s1.st_mode & S_IWGRP) ? 'w' : '-');
	ft_printf("%c", (s1.st_mode & S_IXGRP) ? 'x' : '-');
	ft_printf("%c", (s1.st_mode & S_IROTH) ? 'r' : '-');
	ft_printf("%c", (s1.st_mode & S_IWOTH) ? 'w' : '-');
	ft_printf("%c", (s1.st_mode & S_IXOTH) ? 'x' : '-');
}

void	print_type(char *name)
{
	lstat(name, &s1);
	if (S_ISDIR(s1.st_mode))
		ft_printf("%c", 'd');
	else if (S_ISLNK(s1.st_mode))
		ft_printf("%c", 'l');
	else if (S_ISCHR(s1.st_mode))
		ft_printf("%c", 'c');
	else if (S_ISBLK(s1.st_mode))
	 	ft_printf("%c", 'b');
	else if (S_ISSOCK(s1.st_mode))
		ft_printf("%c", 's');
	else if (S_ISFIFO(s1.st_mode))
		ft_printf("%c", 'f');
	else
		ft_printf("%c", '-');
}

void	ft_count_link(char *name)
{
	stat(name, &s1);
	ft_printf("%3d ", s1.st_nlink);
}

void	print_fin_param(char *dir)
{
	lstat(dir, &s2);
	print_params(dir);
	ft_count_link(dir);
	ft_printf(" ");
	print_pwname(dir);
	print_year(dir);
	print_size(dir);
	print_t(dir);
	ft_printf(" ");
}


