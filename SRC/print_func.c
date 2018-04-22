/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:09:09 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/17 17:09:11 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void				print_with_flag_a(t_dir_names **ds)
{
	int				i;
	int				len_w;
	t_dir_names		*d;

	d = *ds;
	i = 0;
	len_w = d->size_name + 6;
	int z = d->len_dirs;
	if (z > 10)
		len_w -= 3;
	while (z != 0)
	{		
		ft_printf("%-*s", len_w, d->dirs[i]);
		i++;
		z--;
	}
	ft_printf("\n");
}

void				print_without_flags_a(t_dir_names **ds)
{
	int				i;
	int				len_w;
	//char			*tmp;
	t_dir_names		*d;
	// struct winsize 	w;
 //    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
 //    int				mod;

    //printf ("columns %d\n", w.ws_col);
    d = *ds;
	len_w = d->size_name + 6;
	//mod = count_mod(w.ws_col, d->len_dirs);
	i = 0;
		// ft_printf("OK!!!");
	//	 ft_printf(">>%d", d->len_dirs);
	int z = d->len_dirs;
	
	while (z != 0)
	{
		//printf("%d\n", z);
		//getchar();
		//tmp = ft_strdup(d->dirs[i]);
		if (d->dirs[i][0] != '.')
		{
			ft_printf("%-*s", len_w, d->dirs[i]);
		}
		//ft_printf("BBB");
		i++;
		z--;
	}
	//ft_printf("BES");
	ft_printf("\n");
	//	system("leaks ft_ls");
}
