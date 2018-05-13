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

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/ioctl.h>

typedef struct			s_flags
{
	char				*all_flags;
	int					l;
	int					i;
	int					rb;
	int					a;
	int					g;
	int					r;
	int					t;
	int					one;
	int					fz;
	int					er_x;
	int					many_args;
}						t_flags;

typedef struct			s_dir_names
{
	char				**dirs;
	char				*road;
	char				**ar_roads;
	int					len_dirs;
	int					size_name;
	int					flag_f;
}						t_dir_names;

typedef struct			s_err_names
{
	char				*name;
	struct s_err_names	*next;
}						t_err_names;

typedef struct			s_h4
{
	int					ar1;
	int					ar2;
	int					tmp_ar;
	void				**tmp;
	void				**tmp1;
	void				**t;
	void				**t1;
	int					*l1;
	int					*l2;
}						t_h4;

typedef struct			s_len
{
	int					len1;
	int					len2;
}						t_len;

typedef struct			s_ar
{
	int					i;
	int					x;
	int					len_c;
	int					tmp;
}						t_ar;

int						g_er_x;
int						g_er_f;
t_flags					g_com1;
struct stat				s1;
struct stat				s2;
struct group			*grp;
struct passwd			*pwd;

int						search_error(int argc, char **argv);
int						search_error_names(int x, int argc,
											char **argv);
int						is_dir(const char *path);
int						is_file(char *name);
void					free_old(t_dir_names *d);
void					sort_strings(void **tab, void **tab1, int length,
										int (*cmp)());
t_dir_names				*help(char *path, char *name);
t_dir_names				*list_dirs(char *path, char *name);
void					print_with_flag_a(t_dir_names **d, int columns,
											int len_w);
void					print_without_flags_a(t_dir_names **d,
												int columns, int len_w);
char					**sort_errors(char **d, int n);
void					ft_free(t_dir_names **d);
int						ft_for_st_sort(const char *a, const char *b);
void					sort_args(char **argv, int argc, int i);
void					recurse_print(char *path, char *name);
void					recurse_print2(t_dir_names **ds, int i, char *path);
void					no_r_func(char *path, char *name);
int						ft_for_st_sort(const char *a, const char *b);
void					sort_args(char **argv, int argc, int i);
int						ft_for_st_sort2(const char *a, const char *b);
int						ft_for_time_sort(const char *name,
											const char *name2);
void					print_params(struct stat s);
void					print_type(struct stat s);
void					print_dirs(t_dir_names **ds);
void					print_l_flag_a(t_dir_names **ds);
void					print_l_no_flags_a(t_dir_names **ds);
void					print_fin_param(struct stat s);
void					print_total(char **dirs);
void					print_year(struct stat s);
void					print_size(struct stat s);
void					print_t(struct stat s);
void					print_fin_time(char *time);
void					sort_strings2(void **tab, void **tab1, int length);
void					ft_count_link(struct stat s);
void					print_pwname(struct stat s);
int						minor_major(struct stat s);
void					ft_read_link(char *name, struct stat s);
void					inicialization(int *i, int *len_c,
												int len_dirs, int columns);
int						search_column(int len_symb, t_dir_names **ds);
void					print1_without_flags_a(t_dir_names **ds);
void					print1_with_flag_a(t_dir_names **ds);
void					print_i_without_flags_a(t_dir_names **ds,
											int columns, int len_w);
void					print_i_with_flag_a(t_dir_names **ds,
											int columns, int len_w);
void					try_sort(t_dir_names *d);
#endif
