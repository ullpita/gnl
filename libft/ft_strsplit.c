/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:55:25 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/10 18:21:21 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int		count;
	int		sec;

	count = 0;
	sec = 0;
	while (*s)
	{
		if (sec == 0 && *s != c)
		{
			sec = 1;
			count++;
		}
		else if (sec == 1 && *s == c)
			sec = 0;
		s++;
	}
	return (count);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		nbc;

	j = 0;
	nbc = ft_count((char const *)s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nbc + 1))))
		return (NULL);
	tab[nbc] = NULL;
	while (nbc--)
	{
		while (*s == c && *s)
			s++;
		if (!(tab[j] = ft_strsub(s, 0, ft_len(s, c))))
			return (NULL);
		s = s + ft_len(s, c);
		j++;
	}
	return (tab);
}
