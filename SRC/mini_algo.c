/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:14 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/05 18:01:15 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort4(t_stack *a, t_stack *b)
{
	int	i;
	int	zero_pos;
	int	mid;

	i = 0;
	zero_pos = 0;
	mid = a->size / 2;
	while (i < a->size && a->tab[i++] != 0)
		zero_pos++;
	i = 0;
	while (a->tab[i] != 0)
	{
		if (zero_pos < mid)
			ft_rotate(a, 1);
		else
			ft_rotate_rev(a, 1);
	}
	ft_push(a, b);
	ft_sort3(a);
	ft_push(b, a);
}

static void	ft_complete_sort5(t_stack *a, t_stack *b, int mid)
{
	int	i;
	int	zero_pos;

	i = 0;
	zero_pos = 0;
	while (i < a->size && a->tab[i++] != 1)
		zero_pos++;
	i = 0;
	while (a->tab[i] != 1)
	{
		if (zero_pos < mid)
			ft_rotate(a, 1);
		else
			ft_rotate_rev(a, 1);
	}
	ft_push(a, b);
	ft_sort3(a);
	ft_push(b, a);
	ft_push(b, a);
}

void	ft_sort_5_and_4(t_stack *a, t_stack *b)
{
	int	i;
	int	zero_pos;
	int	mid;

	if (a->size == 4)
		ft_sort4(a, b);
	else
	{
		i = 0;
		zero_pos = 0;
		mid = a->size / 2;
		while (i < a->size && a->tab[i++] != 0)
			zero_pos++;
		i = 0;
		while (a->tab[i] != 0)
		{
			if (zero_pos < mid)
				ft_rotate(a, 1);
			else
				ft_rotate_rev(a, 1);
		}
		ft_push(a, b);
		ft_complete_sort5(a, b, mid);
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_sort3(t_stack *a)
{
	int	start;
	int	end;

	start = a->tab[0];
	end = a->tab[2];
	if (end < start && start > a->tab[1])
	{
		ft_rotate(a, 1);
		start = a->tab[0];
	}
	else if (start < a->tab[1] && a->tab[1] > end)
	{
		ft_rotate_rev(a, 1);
		start = a->tab[0];
	}
	if (start > a->tab[1])
		ft_swap(a);
}
