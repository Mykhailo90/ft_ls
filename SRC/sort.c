/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:39:46 by msarapii          #+#    #+#             */
/*   Updated: 2018/04/24 18:39:48 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**sort_errors(char **d, int n)
{
	int 			i;
	char			*str;

	i = 0;
	str = NULL;
	while (i < n - 1)
	{
		if (ft_strcmp(d[i], d[i + 1]) > 0)
		{
			str = d[i];
			d[i] = d[i + 1];
			d[i + 1] = str;
			i = 0;
		}
		else
			i++;
	}
	return (d);
}

void		sort_args(char **argv, int argc, int i)
{
	char	*tmp;
	int		n;

	n = i;
	tmp = NULL;
	while (n < argc - 1)
	{
		
		if (ft_strcmp(argv[n], argv[n + 1]) > 0)
		{
			tmp = argv[n];
			argv[n] = argv[n + 1];
			argv[n + 1] = tmp;
			n = i;
		}
		else
			n++;
	}

}

int		ft_for_st_sort(const char *a, const char *b)
{
	return (ft_strcmp(a, b) > 0);
}

static void		sort2(void **tab, int len1, int len2, int (*cmp)())
{
	int		i1;
	int		i2;
	int		tmp_i;
	void	*tmp[len2 += len1];

	i1 = 0;
	i2 = len1;
	tmp_i = -1;
	while (++tmp_i < len2)
		if (i1 >= len1)
			tmp[tmp_i] = tab[i2++];
		else if (i2 >= len2)
			tmp[tmp_i] = tab[i1++];
		else if (cmp(tab[i1], tab[i2]) > 0)
			tmp[tmp_i] = tab[i2++];
		else
			tmp[tmp_i] = tab[i1++];
	while (--tmp_i >= 0)
		tab[tmp_i] = tmp[tmp_i];
}

void			sort_strings(void **tab, int length, int (*cmp)())
{
	int		len1;
	int		len2;
	void	*tmp;

	if (length > 2)
	{
		len1 = length / 2 + length % 2;
		len2 = length / 2;
		sort_strings(tab, len1, cmp);
		sort_strings(tab + len1, len2, cmp);
		sort2(tab, len1, len2, cmp);
	}
	else if (length == 2 && cmp(tab[0], tab[1]) > 0)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}
