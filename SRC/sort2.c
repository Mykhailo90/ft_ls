/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:15:54 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/25 15:15:55 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_for_time_sort(const char *name, const char *name2)
{
	lstat(name, &s1);
	lstat(name2, &s2);
	return (s1.st_mtime < s2.st_mtime);
}

void				sort_args(char **argv, int argc, int i)
{
	char			*tmp;
	int				n;

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

int					ft_for_st_sort(const char *a, const char *b)
{
	return (ft_strcmp(a, b) > 0);
}

int					ft_for_st_sort2(const char *a, const char *b)
{
	return (ft_strcmp(a, b) < 0);
}
