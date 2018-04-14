/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:53:23 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/23 13:53:25 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				form_ends_string(char *str, size_t *i)
{
	if (g_print < g_size)
		g_buffer[g_print++] = str[(*i)++];
	else
	{
		g_print_len += g_print;
		write(1, g_buffer, g_print);
		ft_bzero(g_buffer, g_size);
		g_print = 0;
		g_buffer[g_print++] = str[(*i)++];
	}
}

void				set_start_parametr(size_t *i)
{
	*i = 0;
	g_print = 0;
	g_error = 0;
	g_print_len = 0;
}

int					check_errors(char *str, size_t *i)
{
	if (g_error == 5)
		while (str[*i] != '%' && str[*i] != '\0')
			*i = *i + 1;
	else if (g_error == 6)
		return (-1);
	else
		while (is_input_spec(str[++(*i) - 1]) == -1)
			;
	return (0);
}

void				help_f(char *str, va_list argptr)
{
	read_com_str(str);
	form_string(argptr, str);
}

int					ft_printf(char *str, ...)
{
	va_list			argptr;
	size_t			i;

	i = 0;
	set_start_parametr(&i);
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!str[++i])
			{
				write_help();
				return (g_print_len);
			}
			help_f(&str[i], argptr);
			if (check_errors(str, &i) == -1)
				return (-1);
		}
		if (str[i] != '\0' && str[i] != '%')
			form_ends_string(str, &i);
	}
	va_end(argptr);
	write_help();
	return (g_print_len);
}
