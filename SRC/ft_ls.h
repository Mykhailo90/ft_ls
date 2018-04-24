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
#include "../libft/libft.h"
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <termios.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/ioctl.h>

typedef struct			s_flags
{
	char				*all_flags;
	int					l;
	int					R;
	int					a;
	int					r;
	int					t;
	int					one;
	int					fz;
	int					er_x;
}						t_flags;

typedef struct			s_dir_names
{
	char 				**dirs;
	int					len_dirs;
	int					size_name;
	int					flag_f;
}						t_dir_names;

typedef struct			s_err_names
{
	char				*name;
	struct s_err_names 	*next;
}						t_err_names;

int						g_er_x;
t_flags					g_com1;

int						search_error(int argc, char **argv);
int						search_error_names(int x, int argc,
											char **argv);
int 					is_dir(const char *path);
int 					is_file(char* name);
void					free_old(t_dir_names *d);
void					sort_strings(void **tab, int length,
										int (*cmp)());
t_dir_names				*help(char *path, char *name);
t_dir_names				*list_dirs(char *path, char *name);
void					print_with_flag_a(t_dir_names **d);
void					print_without_flags_a(t_dir_names **d);
char					**sort_errors(char **d, int n);
void					ft_free(t_dir_names **d);
int						ft_for_st_sort(const char *a, const char *b);
void					sort_args(char **argv, int argc, int i);
void					recurse_print(char *path, char *name);
void					recurse_print2(t_dir_names **ds, int i, char *path);
void					no_r_func(char *path, char *name);
int						ft_for_st_sort(const char *a, const char *b);
void					sort_args(char **argv, int argc, int i);

#endif