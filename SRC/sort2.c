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

int		ft_for_time_sort(const char *name, const char *name2)
{
	lstat(name, &s1);
	lstat(name2, &s2);
	return (s1.st_mtime < s2.st_mtime);
}
