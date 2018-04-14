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

int main(int argc, char **argv)
{
	int i;
	DIR *dir;
	struct dirent *dp;
	static t_flags com;

	i = search_error(argc, argv, &com);
	if (i == argc)
	{
		dir = opendir(".");
		while ((dp = readdir(dir)) != 0)
		{
			ft_printf("%s ", dp->d_name);
		}
	}
	return (0);
}
