/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:02:50 by msarapii          #+#    #+#             */
/*   Updated: 2018/05/11 12:02:51 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					minor_major(struct stat s)
{
	char			*str;

	str = ft_itoa(major(s.st_rdev));
	ft_printf("%3s", str);
	free(str);
	ft_printf(",");
	str = ft_itoa(minor(s.st_rdev));
	ft_printf("%-3s ", str);
	ft_strdel(&str);
	return (1);
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
			ft_strdel(&ds->ar_roads[i]);
			i++;
		}
		if (ds->dirs)
			free(ds->dirs);
		if (ds->ar_roads)
			free(ds->ar_roads);
	}
}

void				print_pwname(struct stat s)
{
	if ((pwd = getpwuid(s.st_uid)) != NULL)
	{
		if (g_com1.l)
			ft_printf("%-10s ", pwd->pw_name);
		else
			ft_printf("%s ", pwd->pw_name);
	}
}

void				print_year(struct stat s)
{
	if ((grp = getgrgid(s.st_gid)) != NULL)
	{
		if (g_com1.l)
			ft_printf("%-15s ", grp->gr_name);
		else
			ft_printf("%s  ", grp->gr_name);
	}
}

void				print_size(struct stat s)
{
	ft_printf("%-5d ", s.st_size);
}
