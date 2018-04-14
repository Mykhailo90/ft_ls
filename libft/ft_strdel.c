/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:22:04 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/21 11:32:43 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strdel(char **as)
{
	if (as)
		ft_memdel((void **)as);
}

void	ft_strdel_uv(unsigned char **as)
{
	if (as)
		ft_memdel((void **)as);
}
