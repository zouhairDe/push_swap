/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:33:51 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/19 01:03:40 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_pivots(t_pivot *pivot, t_stack *a)
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
	while(a->size > 3)
	{
		if (b->size > 1 && a->tab[0] > pivot.last_pivot
			&& b->tab[0] < pivot.sec_pivot && b->tab[0] > pivot.last_pivot)
			ft_rerotate(a, b);
		else if (b->size > 1 && b->tab[0] < pivot.sec_pivot
			&& b->tab[0] > pivot.last_pivot)
			ft_rotate(b, 1);
		if (a->tab[0] >= pivot.first_pivot)
			ft_rotate(a, 1);
		else
			ft_push(b, a);//hna ghaykhsni nder ft_push(t_stack from, t_stack to);
		if (b->size >= pivot.first_pivot)
			init_pivots(&pivot, a);
	}
}

void	ft_a_to_b(t_stack *a, t_stack *b, int tracker)
{
	if (a->tab[0] - 1 == b->tab[0])
		ft_push(b, a);
	else if (a->tab[0] - 1 == b->tab[b->size - 1]) //rrb and pa
		(ft_rotate_rev(b), ft_push(b, a));
}

int	ft_b_to_a(t_stack *a, t_stack *b)
{
	int	tracker;

	tracker = 0;
	while(b->size > 0)
		ft_a_to_b(a, b, tracker);
	while(a->tab[0] - 1 == a->tab[a->size - 1])
		ft_rotate(a, 1);
}