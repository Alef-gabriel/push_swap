/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:27:32 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 16:18:02 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char **nptr)
{
	int	i;
	int	j;

	i = 0;
	while (nptr[i])
	{
		j = 0;
		while (nptr[i][j])
		{
			if (j == 0 && (nptr[i][j] == '-' || nptr[i][j] == '+'))
				j++;
			else if (!(nptr[i][j] >= '0' && nptr[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

int	is_sorted(int *array, int size)
{
	int	aux;
	int	j;

	j = 0;
	while (j < size)
	{
		aux = array[j++];
		if (aux > array[j])
			return (1);
		else if (j + 1 == size)
			j++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}
