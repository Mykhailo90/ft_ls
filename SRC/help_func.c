/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:02:14 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/17 17:02:16 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_args(char **argv, int argc, int i)
{
	char	*tmp;
	int		n;

	n = i;
	tmp = NULL;
	while (n < argc - 1)
	{
		
		if (ft_strcmp(argv[n], argv[n + 1]) > 0)
		{
			tmp = argv[n];
			argv[n] = argv[n + 1];
			argv[n + 1] = tmp;
			n = i;
		}
		else
			n++;
	}

}

/*
int		ft_for_r_sort(const char *a, const char *b)
{
	return (ft_strcmp(a, b) < 0);
}

int		ft_for_t_sort(const char *a, const char *b)
{
	lstat(a, &sb);
	lstat(b, &sb2);
	return (sb.st_mtime < sb2.st_mtime);
}
*/
int		ft_for_st_sort(const char *a, const char *b)
{
	return (ft_strcmp(a, b) > 0);
}




static void		merge(void **tab, int len1, int len2, int (*cmp)())
{
	int		i1;
	int		i2;
	int		tmp_i;
	void	*tmp[len2 += len1];

	i1 = 0;
	i2 = len1;
	tmp_i = -1;
	while (++tmp_i < len2)
		if (i1 >= len1)
			tmp[tmp_i] = tab[i2++];
		else if (i2 >= len2)
			tmp[tmp_i] = tab[i1++];
		else if (cmp(tab[i1], tab[i2]) > 0)
			tmp[tmp_i] = tab[i2++];
		else
			tmp[tmp_i] = tab[i1++];
	while (--tmp_i >= 0)
		tab[tmp_i] = tmp[tmp_i];
}

void			sort_strings(void **tab, int length, int (*cmp)())
{
	int		len1;
	int		len2;
	void	*tmp;

	if (length > 2)
	{
		len1 = length / 2 + length % 2;
		len2 = length / 2;
		sort_strings(tab, len1, cmp);
		sort_strings(tab + len1, len2, cmp);
		merge(tab, len1, len2, cmp);
	}
	else if (length == 2 && cmp(tab[0], tab[1]) > 0)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}


int 				is_file(char* name)
{
    DIR* 			directory;

    directory = opendir(name);
    if(directory != NULL)
    {
   		closedir(directory);
    	return 0;
    }
	if(errno == ENOTDIR)
	{
		return 1;
    }
	return -1;
}

int 				is_dir(const char *path)
{
    struct stat 	s;

    lstat(path, &s);
    if (S_ISDIR(s.st_mode))
        return (1);
    return (0);
}

void				free_old(t_dir_names *d)
{
	int i;

	i = 0;
	while (d->dirs[i])
	{
		ft_strdel(&d->dirs[i]);
		i++;
	}
	free(d->dirs);
}

char				**sort_errors(char **d, int n)
{
	int 			i;
	char			*str;

	i = 0;
	str = NULL;
	while (i < n - 1)
	{
		if (ft_strcmp(d[i], d[i + 1]) > 0)
		{
			str = d[i];
			d[i] = d[i + 1];
			d[i + 1] = str;
			i = 0;
		}
		else
			i++;
	}
	return (d);
}

/*t_dir_names				*sort_strings(t_dir_names **ds)
{
	int 			i;
	char			*str;
	t_dir_names		*d;
	int				len;

	d = *ds;
	len = d->len_dirs;
	i = 0;
	while (i < len - 1)
	{
		if (ft_strcmp(d->dirs[i], d->dirs[i + 1]) > 0)
		{
			str = d->dirs[i];
			d->dirs[i] = d->dirs[i + 1];
			d->dirs[i + 1] = str;
			i = 0;
		}
		else
			i++;
	}
	return (d);
}
*/
t_dir_names			*help(char *path, t_flags *com, char *name)
{
	static t_dir_names 	*d;

	d = list_dirs(path, com, name);

	if (d)
	{
		sort_strings((void **)d->dirs, d->len_dirs, ft_for_st_sort);
		if (com->fz == 0 && g_er_x == 0)
			ft_printf("%s:\n", name);

		if (com->fz == 1) 
	 	{
	 		if (g_er_x != 1)
	 			ft_printf("\n");
	 		g_er_x = 0;
	 		
	 			ft_printf("%s:\n", name);
	 	}

		(com->a) ? print_with_flag_a(&d) : print_without_flags_a(&d);

		d->flag_f = 1;
	}
		if (name)
	 	ft_strdel(&name);
	 	if (path)
	 	ft_strdel(&path);
	return (d);
}
/*
void				help_mod(char *path, t_dir_names *d)
{
	list_dirs_mod(path, d);
	ft_printf("GRGRGRG\n");
	sort_strings(d);
	print_without_flags_a(d);
	d->flag_f = 1;
}
*/