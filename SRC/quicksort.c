/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:33:51 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/12 17:39:21 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_pivots(t_pivot *pivot, t_stack *a)
{
	pivot->last_pivot = pivot->first_pivot;
	pivot->sec_pivot = a->size / 6 + pivot->first_pivot;
	pivot->first_pivot = a->size / 3 + pivot->first_pivot;
}

void	ft_quicksort(t_stack *a, t_stack *b)
{
	t_pivot	pivot;

	pivot.last_pivot = -1;
	pivot.first_pivot = 0;
	pivot.sec_pivot = a->size / 6 + pivot.first_pivot;
	pivot.first_pivot = a->size / 3 + pivot.first_pivot;
	while (a->size > 3)
	{
		if (b->size > 1 && a->tab[0] >= pivot.first_pivot
			&& b->tab[0] < pivot.sec_pivot && b->tab[0] > pivot.last_pivot)
			ft_rerotate(a, b);
		else if (b->size > 1 && b->tab[0] < pivot.sec_pivot
			&& b->tab[0] > pivot.last_pivot)
			ft_rotate(b, 1);
		if (a->tab[0] >= pivot.first_pivot)
			ft_rotate(a, 1);
		else
			ft_push(a, b);
		if (b->size >= pivot.first_pivot)
			ft_init_pivots(&pivot, a);
	}
}

static int	get_pos(t_stack *b, int a_tab)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (b->tab[i] == a_tab)
			return (i);
		i++;
	}
	return (i);
}

static void	ft_b_too_a(t_stack *a, t_stack *b, int *tracker)
{
	int	pos;

	if (a->tab[0] - 1 == b->tab[0])
		(ft_push(b, a));
	else if (a->tab[0] - 1 == b->tab[b->size - 1])
		(ft_rotate_rev(b, 1), ft_push(b, a));
	else if (!(*tracker))
		(ft_push(b, a), ft_rotate(a, 1), (*tracker)++);
	else if (a->tab[0] - 1 == a->tab[a->size - 1])
		(ft_rotate_rev(a, 1), (*tracker)--);
	else if (b->tab[0] > a->tab[a->size - 1])
		(ft_push(b, a), ft_rotate(a, 1), (*tracker)++);
	else if (a->tab[a->size - 1] < b->tab[b->size - 1])
		(ft_rotate_rev(b, 1), ft_push(b, a), ft_rotate(a, 1), (*tracker)++);
	else
	{
		pos = get_pos(b, a->tab[0] - 1);
		if (pos <= b->size / 2)
			ft_rotate(b, 1);
		else
			ft_rotate_rev(b, 1);
	}
}

void	ft_b_to_a(t_stack *a, t_stack *b)
{
	int	tracker;

	tracker = 0;
	while (b->size > 0)
		ft_b_too_a(a, b, &tracker);
	while (a->tab[0] - 1 == a->tab[a->size - 1])
		ft_rotate_rev(a, 1);
}
