/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:26:56 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 14:29:35 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	game(char *cmd, t_list *data)
{
	if (ft_memcmp(cmd, "pa", 3) == 0)
		push(data->b, data->a, data->size_a - data->size_b, data->size_b);
	else if (ft_memcmp(cmd, "ra", 3) == 0)
		to_lat(data->a, data->size_a - data->size_b);
	else if (ft_memcmp(cmd, "pb", 3) == 0)
		push(data->a, data->b, data->size_b, data->size_a - data->size_b);
	ft_write_str(cmd);
	write(1, "\n", 1);
	return (1);
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	aux;

	while (is_sorted(array, size))
	{
		i = 0;
		while (i < size)
		{
			if (i + 1 == size)
				break ;
			else if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
			}
			i++;
		}
	}
}

void	cpyint(int *arr, int *cpy, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
}

static int	indexx(t_list *arr, int pivot, int size)
{
	int	i;

	i = 0;
	if (arr->sorted == NULL)
	{
		arr->sorted = (int *)malloc(sizeof(int) * arr->size_a);
		cpyint(arr->a, arr->sorted, arr->size_a);
		bubble_sort(arr->sorted, arr->size_a);
	}
	while (i < size)
	{
		if (arr->sorted[i] == pivot)
			break ;
		i++;
	}
	return (i);
}

void	radix_swap(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (is_sorted(data->a, data->size_a))
	{
		j = 0;
		while (j < data->size_a)
		{
			data->pivot = indexx(data, data->a[0], data->size_a);
			if ((data->pivot >> i) & 1)
				game("ra", data);
			else
				data->size_b += game("pb", data);
			j++;
		}
		while (data->size_b)
			data->size_b -= game("pa", data);
		i++;
	}
}
