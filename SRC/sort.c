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
	int				i;
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

void				h4(t_h4 *h, int (*cmp)())
{
	if (h->ar1 >= *(h->l1))
	{
		h->tmp[h->tmp_ar] = h->t[h->ar2];
		h->tmp1[h->tmp_ar] = h->t1[(h->ar2)++];
	}
	else if (h->ar2 >= *(h->l2))
	{
		h->tmp[h->tmp_ar] = h->t[h->ar1];
		h->tmp1[h->tmp_ar] = h->t1[(h->ar1)++];
	}
	else if (cmp(h->t[h->ar1], h->t[h->ar2]) > 0)
	{
		h->tmp[h->tmp_ar] = h->t[h->ar2];
		h->tmp1[h->tmp_ar] = h->t1[(h->ar2)++];
	}
	else
	{
		h->tmp[h->tmp_ar] = h->t[h->ar1];
		h->tmp1[h->tmp_ar] = h->t1[(h->ar1)++];
	}
}

void				sort2(void **tab, void **tab1, t_len l, int (*cmp)())
{
	t_h4			*h;

	h = malloc(sizeof(t_h4));
	h->tmp = malloc(sizeof(void *) * (l.len2 + l.len1));
	h->tmp1 = malloc(sizeof(void *) * (l.len2 += l.len1));
	h->ar1 = 0;
	h->ar2 = l.len1;
	h->tmp_ar = -1;
	h->t = tab;
	h->t1 = tab1;
	h->l1 = &l.len1;
	h->l2 = &l.len2;
	while (++(h->tmp_ar) < *(h->l2))
		h4(h, cmp);
	while (--(h->tmp_ar) >= 0)
	{
		h->t[h->tmp_ar] = h->tmp[h->tmp_ar];
		h->t1[h->tmp_ar] = h->tmp1[h->tmp_ar];
	}
	free(h->tmp);
	free(h->tmp1);
	free(h);
}

void				sort_strings(void **tab, void **tab1,
									int length, int (*cmp)())
{
	t_len			l;
	void			*tmp;
	void			*tmp1;

	if (length > 2)
	{
		l.len1 = length / 2 + length % 2;
		l.len2 = length / 2;
		sort_strings(tab, tab1, l.len1, cmp);
		sort_strings(tab + l.len1, tab1 + l.len1, l.len2, cmp);
		sort2(tab, tab1, l, cmp);
	}
	else if (length == 2 && cmp(tab[0], tab[1]) > 0)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
		tmp1 = tab1[0];
		tab1[0] = tab1[1];
		tab1[1] = tmp1;
	}
}

void				sort_strings2(void **tab, void **tab1, int length)
{
	int				i;
	int				n;
	void			*tmp;
	void			*tmp1;

	i = 0;
	n = length - 1;
	while (i < (length / 2))
	{
		tmp = tab[i];
		tab[i] = tab[n];
		tab[n] = tmp;
		tmp1 = tab1[i];
		tab1[i] = tab1[n];
		tab1[n] = tmp1;
		i++;
		n--;
	}
}
