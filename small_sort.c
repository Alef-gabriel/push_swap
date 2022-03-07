/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:27:03 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 16:17:43 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	game2(char *cmd, t_list *data)
{
	if (ft_memcmp(cmd, "sa", 3) == 0)
		swap(data->a);
	if (ft_memcmp(cmd, "sb", 3) == 0)
		swap(data->b);
	if (ft_memcmp(cmd, "rra", 3) == 0)
		to_first(data->a, data->size_a - data->size_b);
	if (ft_memcmp(cmd, "rrb", 3) == 0)
		to_first(data->b, data->size_b);
	if (ft_memcmp(cmd, "rb", 3) == 0)
		to_lat(data->b, data->size_b);
	ft_write_str(cmd);
	write(1, "\n", 1);
	return (1);
}

static int	checker(int i, t_list *data, char a)
{
	if (i != -1 && a == 'a')
	{
		if (data->a[0] > data->a[(data->size_a - data->size_b) - 1]
			&& data->a[0] > data->a[(data->size_a - data->size_b) - 2])
			return (-game("ra", data));
		else if (data->a[0] > data->a[(data->size_a - data->size_b) - 1]
			&& data->a[1] > data->a[(data->size_a - data->size_b) - 1])
			return (-game2("rra", data));
	}
	else
	{
		if (data->b[0] < data->b[data->size_b - 1]
			&& data->b[0] < data->b[data->size_b - 2] && i != -1)
			return (-game2("rb", data));
		else if (data->b[0] < data->b[data->size_b - 1]
			&& data->b[1] < data->b[data->size_b - 1] && i != -1)
			return (-game2("rrb", data));
	}
	return (i);
}

static int	b_sorted(int *array, int size)
{
	int	aux;
	int	j;

	j = 0;
	while (j < size)
	{
		aux = array[j++];
		if (aux < array[j])
			return (1);
		else if (j + 1 == size)
			j++;
	}
	return (0);
}

void	small(t_list *data)
{
	int		j;
	int		i;

	i = 0;
	while (is_sorted(data->a, data->size_a - data->size_b))
	{
		data->pivot = data->a[i];
		j = 0;
		while (j < data->size_a - data->size_b)
		{
			if (data->a[0] > data->a[1])
				i = -game2("sa", data);
			i = checker(i, data, 'a');
			if (data->pivot > data->a[j] && i != -1)
			{
				i = -game("pb", data);
				data->size_b++;
			}
			if (i == -1)
				break ;
			j++;
		}
		i++;
	}
}

void	small_b(t_list *data)
{
	int		j;
	int		i;

	i = 0;
	while (data->size_b)
	{
		data->pivot = data->b[i];
		j = 0;
		while (j < data->size_b)
		{
			if (data->b[0] < data->b[1])
				i = -game2("sb", data);
			i = checker(i, data, 'b');
			if ((data->pivot > data->b[j]
					|| !b_sorted(data->b, data->size_b)) && i != -1)
			{
				i = -game("pa", data);
				data->size_b--;
			}
			if (i == -1)
				break ;
			j++;
		}
		i++;
	}
}
