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

void	print_t(struct stat s)
{
	char	*t;
	int		i;
	int		len;

	i = 0;
	len = 0;
	t = ctime(&s.st_mtime);
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

void	print_type(struct stat s)
{
	if (S_ISDIR(s.st_mode))
		ft_printf("%c", 'd');
	else if (S_ISLNK(s.st_mode))
		ft_printf("%c", 'l');
	else if (S_ISCHR(s.st_mode))
		ft_printf("%c", 'c');
	else if (S_ISBLK(s.st_mode))
		ft_printf("%c", 'b');
	else if (S_ISSOCK(s.st_mode))
		ft_printf("%c", 's');
	else if (S_ISFIFO(s.st_mode))
		ft_printf("%c", 'f');
	else
		ft_printf("%c", '-');
}

void	ft_count_link(struct stat s)
{
	ft_printf("%3d ", s.st_nlink);
}

void	print_fin_param(struct stat s)
{
	print_params(s);
	ft_count_link(s);
	ft_printf(" ");
	if (g_com1.g != 1)
	{
		print_pwname(s);
		ft_printf(" ");
	}
	print_year(s);
	ft_printf(" ");
	if (S_ISCHR(s.st_mode) || S_ISBLK(s.st_mode))
		minor_major(s);
	else
		print_size(s);
	ft_printf("\t");
	print_t(s);
	ft_printf("\t");
}
