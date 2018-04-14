/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:17:08 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/03 12:17:10 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_valid_ch(char ch)
{
	int		num;
	int		i;
	char	*str;

	num = 0;
	i = 0;
	str = "0123456789ABCDEF";
	while (str[i] != '\0')
	{
		if (str[i] == ft_toupper(ch))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_pow(int num, int pow)
{
	int result;

	result = 1;
	while (pow > 0)
	{
		result *= num;
		pow--;
	}
	return (result);
}

int		ft_atoi_base(char *str, int base)
{
	int num;
	int pow;
	int c;

	num = 0;
	c = 1;
	pow = ft_strlen(str) - 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (ft_valid_ch(*str) != -1 && *str)
	{
		num += ft_valid_ch(*str) * ft_pow(base, pow);
		pow--;
		str++;
	}
	return (num * c);
}
