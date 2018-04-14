/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 06:29:19 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 18:13:02 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		count_symbols(long long n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (i + 1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void			input_symbols(char *res, long long n, size_t len)
{
	if (n < 0)
	{
		res[0] = '-';
		res = res + len;
		n *= -1;
	}
	else
		res = res + len - 1;
	while (len--)
	{
		*(res--) = ('0' + n % 10);
		n = n / 10;
	}
}

char				*ft_itoa(long long n)
{
	char			*res;
	size_t			len;
	char			*num;
	char			*start;

	num = "-9223372036854775808";
	len = count_symbols(n);
	if (n == -9223372036854775807 - 1)
	{
		res = ft_strdup(num);
		return (res);
	}
	res = (n > 0) ? ft_strnew(sizeof(char) * len) :
					ft_strnew(sizeof(char) * len + 1);
	start = res;
	input_symbols(&res[0], n, len);
	return (start);
}
