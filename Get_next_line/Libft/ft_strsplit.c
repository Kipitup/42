/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:39:40 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 15:28:26 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
			count++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (count);
}

static void		ft_clean(char **tab, int i)
{
	while (--i >= 0)
		ft_strdel(&tab[i]);
	free(tab);
	tab = NULL;
}

static char		**ft_fill(char const *s, char c, char **tab, int count)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < count)
	{
		j = 0;
		k = 0;
		while (*s == c && *s)
			s++;
		while ((s[j] != c) && s[j])
			j++;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (j + 1))))
		{
			ft_clean(tab, i);
			return (NULL);
		}
		while (--j >= 0)
			tab[i][k++] = (char)*s++;
		tab[i][k] = '\0';
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**tab;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ft_fill(s, c, tab, count);
	return (tab);
}
