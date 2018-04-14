/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:18:46 by msarapii          #+#    #+#             */
/*   Updated: 2018/03/29 20:18:47 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_convert1(unsigned long long n)
{
	if ((n > 0 && n <= 9) || n == 0)
		return ('0' + n);
	else if (n >= 10 && n <= 35)
		return ('a' + n - 10);
	else
		return (0);
}

static char			ft_convert2(unsigned long long n)
{
	if ((n > 0 && n <= 9) || n == 0)
		return ('0' + n);
	else if (n >= 10 && n <= 35)
		return ('A' + n - 10);
	else
		return (0);
}

char				*ft_it(unsigned long long num, int base, char ch)
{
	char			*str;
	char			*tmp;
	int				i;
	int				n;

	i = 64;
	n = 0;
	str = ft_strnew(i--);
	str = ft_memset(str, ' ', 63);
	while (num >= (unsigned long long)base)
	{
		str[i--] = (ch == 'x' || ch == 'p') ? ft_convert1(num % base) :
												ft_convert2(num % base);
		num = num / base;
	}
	str[i] = (ch == 'x' || ch == 'p') ? ft_convert1(num % base) :
												ft_convert2(num % base);
	while (str[n++] == ' ')
		;
	tmp = ft_strdup(&str[n - 1]);
	ft_strdel(&str);
	str = tmp;
	return (str);
}

char				*ft_itoa_base(unsigned long long number, char ch)
{
	char			*res;

	res = ft_strnew(1);
	if (number == 0)
		res[0] = '0';
	else if (ch == 'x' || ch == 'X' || ch == 'p')
		res = ft_strjoin(res, ft_it(number, 16, ch));
	else if (ch == 'O' || ch == 'o')
		res = ft_strjoin(res, ft_it(number, 8, ch));
	return (res);
}
