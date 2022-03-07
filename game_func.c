/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:26:38 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 22:46:44 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *array)
{
	int		var;

	var = array[0];
	array[0] = array[1];
	array[1] = var;
}

void	push(int *donor, int *receiver, int sizereceiv, int sizedonor)
{
	int		i;
	int		aux;
	int		var;

	i = 0;
	aux = donor[i];
	while (i < sizereceiv)
	{
		var = receiver[i];
		receiver[i++] = aux;
		aux = var;
	}
	receiver[i] = aux;
	i = 0;
	while (i < sizedonor)
	{
		if (i + 1 == sizedonor)
			break ;
		donor[i] = donor[i + 1];
		i++;
	}
}

void	to_first(int *array, int size)
{
	int		i;
	int		aux;
	int		var;

	i = 0;
	aux = array[size - 1];
	while (i < size)
	{
		var = array[i];
		array[i++] = aux;
		aux = var;
	}
}

void	to_lat(int *array, int size)
{
	int		i;
	int		aux;
	int		var;

	i = 0;
	aux = array[i];
	while (i < size)
	{
		var = array[(size - 1) - i];
		array[(size - 1) - i++] = aux;
		aux = var;
	}
}

void	free_and_exit(t_list *arr, int error, char **arr2)
{
	if (arr2 != NULL)
		free_all(arr2);
	if (arr->a != NULL)
		free(arr->a);
	if (arr->b != NULL)
		free(arr->b);
	if (arr->sorted != NULL)
		free(arr->sorted);
	else if (error >= 1)
		ft_write_str("Error\n");
	exit(1);
}
