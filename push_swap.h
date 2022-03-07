/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:26:48 by algabrie          #+#    #+#             */
/*   Updated: 2022/01/13 23:02:42 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int		*a;
	int		*b;
	int		*sorted;
	int		size_a;
	int		size_b;
	int		pivot;
}	t_list;

long int	ft_atoi(const char *nptr);

void		ft_write_str(char *str);

int			is_digit(char **nptr);

int			ft_memcmp(const char *s1, const char *s2, size_t n);

void		swap(int *array);

void		push(int *donor, int *receiver, int sizereceiv, int sizedonor);

void		to_first(int *array, int size);

void		to_lat(int *array, int size);

int			is_sorted(int *array, int size);

void		bubble_sort(int *array, int size);

void		radix_swap(t_list *data);

void		cpyint(int *arr, int *cpy, int size);

void		free_and_exit(t_list *arr, int error, char **arr2);

char		**ft_split(char const *s, char c);

size_t		ft_strlen(const char *s);

void		free_all(char **arr);

void		cpyint(int *arr, int *cpy, int size);

int			game(char *cmd, t_list *data);

void		small(t_list *data);

void		small_b(t_list *data);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif