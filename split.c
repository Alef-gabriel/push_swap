/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:07:09 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/12 13:21:47 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	wrd_cont(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	return (i + 1);
}

static char	*apply(char const *s, char c)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	p = (char *)malloc(i + 1);
	p[i--] = 0;
	i = 0;
	while (*s != c && *s != 0)
	{
		p[i++] = *s;
		s++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	split = (char **)malloc(sizeof(char *) * wrd_cont(s, c));
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != 0)
			split[k++] = apply(s, c);
		while (*s != c && *s != 0)
			s++;
	}
	split[k++] = 0;
	return (split);
}
