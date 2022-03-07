/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:26:27 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 23:14:55 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static void	str_to_int(char **arr, t_list *data, int size, int boomaloc)
{
	int			i;
	long int	aux;

	i = 0;
	while (i < size)
	{
		aux = ft_atoi(arr[i]);
		if (aux > 2147483647)
		{
			if (boomaloc)
				free_and_exit(data, 1, arr);
			free_and_exit(data, 1, NULL);
		}
		data->a[i] = aux;
		i++;
	}
}

static void	is_repeated(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (j < data->size_a)
		{
			if (j == i)
				j++;
			else if (data->a[j] == data->a[i])
				free_and_exit(data, 1, NULL);
			j++;
		}
		i++;
	}
}

static void	fill_in_a(char **arr, t_list *data)
{
	char	**split;

	if (data->size_a == 1)
	{
		split = ft_split(arr[1], ' ');
		data->size_a = ft_len(split);
		data->a = (int *)malloc(sizeof(int) * data->size_a);
		if (!is_digit(split))
			free_and_exit(data, 1, split);
		str_to_int(split, data, data->size_a, 1);
		if (data->size_a <= 1)
			free_and_exit(data, 0, split);
		free_all(split);
	}
	else
	{
		if (!is_digit(arr + 1))
			free_and_exit(data, 1, NULL);
		if (data->size_a == 0)
			free_and_exit(data, 0, NULL);
		data->a = (int *)malloc(sizeof(int) * data->size_a);
		str_to_int(arr + 1, data, data->size_a, 0);
	}
}

int	main(int argc, char *argv[])
{
	t_list	data;

	data.a = NULL;
	data.b = NULL;
	data.sorted = NULL;
	data.size_a = argc - 1;
	data.size_b = 0;
	fill_in_a(argv, &data);
	data.b = (int *)malloc(sizeof(int) * data.size_a);
	is_repeated(&data);
	if (data.size_a < 10)
	{
		while (1)
		{
			if (!is_sorted(data.a, data.size_a - data.size_b)
				&& data.size_b == 0)
				break ;
			small(&data);
			small_b(&data);
		}
	}
	else
		radix_swap(&data);
	free_and_exit(&data, 0, NULL);
	return (0);
}
