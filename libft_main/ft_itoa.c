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

#include "libft.h"

static size_t		count_symbols(long int n)
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

static void			input_symbols(char *res, long int n, size_t len)
{
	if (n < 0)
	{
		res[0] = '-';
		res[len + 1] = '\0';
		res = res + len;
		n = -n;
	}
	else
	{
		res[len] = '\0';
		res = res + len - 1;
	}
	while (len--)
	{
		*(res--) = ('0' + n % 10);
		n = n / 10;
	}
}

char				*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	char			*start;
	long int		num;

	num = (long int)n;
	len = count_symbols(num);
	res = NULL;
	if (num < 0 && (!(res = ft_memalloc(sizeof(char) * len + 2))))
		return (NULL);
	if (num >= 0 && (!(res = ft_memalloc(sizeof(char) * len + 1))))
		return (NULL);
	start = res;
	input_symbols(start, num, len);
	return (start);
}
