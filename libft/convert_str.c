/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:56:54 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/26 15:56:55 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				func_help4(wchar_t *tmp, unsigned char *res,
								t_help *a, int len)
{
	if (tmp[a->i] <= 1114111)
	{
		a->number = a->number + 4;
		if (a->number <= len)
		{
			res[a->n] = ((tmp[a->i] >> 18) + 0b11110000);
			a->n = a->n + 1;
			res[a->n] = (((tmp[a->i] >> 12) & 0b111111) + 0b10000000);
			a->n = a->n + 1;
			res[a->n] = (((tmp[a->i] >> 6) & 0b111111) + 0b10000000);
			a->n = a->n + 1;
			res[a->n] = ((tmp[a->i] & 0b111111) + 0b10000000);
			a->n = a->n + 1;
		}
	}
}

static void				func_help3(wchar_t *tmp, unsigned char *res,
								t_help *a, int len)
{
	if (tmp[a->i] <= 65535)
	{
		a->number = a->number + 3;
		if (a->number <= len)
		{
			res[a->n] = ((tmp[a->i] >> 12) + 0b11100000);
			a->n = a->n + 1;
			res[a->n] = (((tmp[a->i] >> 6) & 0b111111) + 0b10000000);
			a->n = a->n + 1;
			res[a->n] = ((tmp[a->i] & 0b111111) + 0b10000000);
			a->n = a->n + 1;
		}
	}
	else
		func_help4(tmp, res, a, len);
}

static void				func_help2(wchar_t *tmp, unsigned char *res,
									t_help *arg, int len)
{
	if (tmp[arg->i] <= 2047)
	{
		arg->number = arg->number + 2;
		if (arg->number <= len)
		{
			res[arg->n] = ((tmp[arg->i] >> 6) + 0b11000000);
			arg->n = arg->n + 1;
			res[arg->n] = ((tmp[arg->i] & 0b111111) + 0b10000000);
			arg->n = arg->n + 1;
		}
	}
	else
		func_help3(tmp, res, arg, len);
}

void					func_help1(wchar_t *tmp, unsigned char *res,
								int len)
{
	t_help				arg;

	arg.i = 0;
	arg.n = 0;
	arg.number = 0;
	while (tmp[arg.i] && arg.number <= len)
	{
		if (tmp[arg.i] <= 127)
		{
			arg.number = arg.number + 1;
			if (arg.number <= len)
			{
				res[arg.n] = (unsigned char)tmp[arg.i];
				arg.n = arg.n + 1;
			}
		}
		else
			func_help2(tmp, res, &arg, len);
		arg.i = arg.i + 1;
	}
}

unsigned char			*convert_in_str1(wchar_t *tmp, int l)
{
	unsigned char		*res;

	res = (unsigned char *)ft_strnew(l);
	func_help1(tmp, res, l);
	return (res);
}
