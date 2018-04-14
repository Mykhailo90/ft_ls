/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:11:36 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/14 13:11:37 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <termios.h>
# include <sys/stat.h>

typedef struct	s_flags
{
	char		*all_flags;
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
	int			one;
}				t_flags;

int			search_error(int argc, char **argv, t_flags *com);

#endif