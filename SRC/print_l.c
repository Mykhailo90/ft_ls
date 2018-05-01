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

void	ft_printf_param(char *name)
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

void	ft_printf_file_type(char *name)
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
