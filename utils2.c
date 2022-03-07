/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:37:58 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 23:01:56 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *nptr)
{
	long int	stg;
	int			signal;
	int			i;

	stg = 0;
	if (!nptr)
		return (0);
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		signal = -1;
	else
		signal = 1;
	if (signal == -1 || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		stg = (stg * 10) + (nptr[i++] - '0');
	return (stg * signal);
}

void	ft_write_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
