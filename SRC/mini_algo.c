/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:14 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/24 23:25:33 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
