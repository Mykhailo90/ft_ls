/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:49:06 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/23 13:49:09 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <locale.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <inttypes.h>
# include <stddef.h>
# include <wchar.h>

typedef struct			s_list
{
	char				specificator;
	char				flags[6];
	char				width[1024];
	char				pr[1024];
	char				size[9];
}						t_list;

typedef struct			s_help
{
	int					i;
	int					n;
	int					number;
	char				*tmp;
}						t_help;

static const size_t		g_size = 1024;
char					g_buffer[1024];
size_t					g_print;
size_t					g_print_len;
int						g_error;
t_list					g_com;

int						ft_printf(char *str, ...);
int						is_input_spec(char ch);
void					*ft_memalloc(size_t size);
unsigned char			*ft_strcat_uv(unsigned char *dest,
										const unsigned char *src);
unsigned char			*ft_strcpy_uv(unsigned char *dest,
										const unsigned char *src);
size_t					ft_strlen_uv(const unsigned char *s);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strcat(char *dest, const char *src);
size_t					ft_strlen_uv(const unsigned char *s);
void					ft_memdel(void **ap);
char					*ft_itoa(long long n);
void					add_esp(char **str);
void					add_null_before(char **str);
void					add_null(char **str);
char					*ft_strjoin(char *s1, char *s2);
void					search_specificator(char *str);
void					set_list_null();
void					read_com_str(char *str);
void					search_flags(char *str);
int						search_dif_fl(char *str, char x);
int						search_fl_n(char *str);
int						is_it_flags(char ch);
int						ft_isdigit(int character);
void					ft_bzero(void *s, size_t n);
char					*ft_strncpy(char *dest,
								const char *src, size_t n);
void					ft_strdel(char **as);
void					ft_strdel_u(unsigned char **as);
void					search_width(char *str);
void					search_pr(char *str);
void					search_size(char *str);
int						is_it_size(char ch);
size_t					len_s(char *str);
int						search_hl(char *str);
int						check_size(char ch);
void					add_null_in_c(char ch);
void					add_esp_for_c(char symbol);
void					add_esp_for_c_end(char ch);
void					print_symbol(char symbol);
int						ft_atoi(const char *nptr);
void					search_errors(char **str);
void					form_string(va_list argptr, char *str);
int						ft_is_it_space(char ch);
int						input_symb(char *str, char ch);
void					input_text(char **str, int len);
void					search_sp_d(va_list argptr);
size_t					ft_strlen(const char *s);
char					*ft_strnew(size_t size);
void					help_func(char **str, char **tmp, int *n, int *i);
void					full_n(char **tmp, int i, int n);
void					search_sp_dv(va_list argptr, char ch);
void					prepare_str_ex(void);
void					add_null_in_s(char **res_str);
char					*prepare_str(char *str);
char					*ft_itoa_u(unsigned long long n);
void					add_esp_for_s(char **str);
void					add_esp_for_s_end(char **str);
int						size_wt(wchar_t *tmp);
unsigned char			*convert_in_str(wchar_t *tmp);
void					add_null_in_cv(unsigned char **str);
void					add_esp_for_cv_end(unsigned char **str);
void					ft_strdel_uv(unsigned char **as);
void					search_sp_s(va_list argptr, char ch);
unsigned char			*ft_strjoin_uv(unsigned char *s1,
								unsigned char *s2);
void					add_esp_for_cv(unsigned char **str);
unsigned char			*convert_in_str1(wchar_t *tmp, int l);
void					func_help1(wchar_t *tmp, unsigned char *res,
								int len);
void					prepare_str_sv(unsigned char **res_str);
void					search_sp_u(va_list argptr);
void					prepare_str_u(char **str);
void					search_sp_p(unsigned long int tmp, char ch);
unsigned char			*search_sp_c(long n, char s);
void					form_p3_help(char ch, unsigned long long tp,
										char **res);
void					add_hesh_o(char **res);
char					*ft_itoa_base(unsigned long long number, char ch);
void					add_hesh(char **res, char ch);
void					add_null_before_xv(char **str, char ch);
char					*search_sp_x(unsigned long long n, char ch);
char					*prepare_str_s(char **res_str);
void					add_null_before_pr(char **str);
void					add_null_after_w(char **str);
void					add_null_before_u(char **str);
char					*prepare_str_c(char ch);
void					prepare_str_cvl(char **str);
void					prep_help(char **res);
char					*ft_strdup(const char *s);
void					add_null_in_cvr(char **str);
void					add_esp_one(char **str);
void					*ft_memset(void *s, int c, size_t n);
void					write_help(void);
void					help_func_p(unsigned long long tp, char **nol,
							char **res, char ch);
void					help_search2(char **str, int *n, char **r,
										char **result);
void					form_p2_help(long *tmp, char ch, va_list argptr);
#endif
