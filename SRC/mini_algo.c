/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:14 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 02:52:58 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack *a)
{
	if (a->numbers[0] > a->numbers[1] && a->numbers[0] < a->numbers[2])
		ft_swap(a);
	else if (a->numbers[0] > a->numbers[1] && a->numbers[0] > a->numbers[2])
		ft_rotate_rev(a);
	else if (a->numbers[0] > a->numbers[1] && a->numbers[0] > a->numbers[2])
		ft_rotate(a, 1);
	else if (a->numbers[0] < a->numbers[1] && a->numbers[0] > a->numbers[2])
		ft_rotate_rev(a);
	else if (a->numbers[0] < a->numbers[1] && a->numbers[0] < a->numbers[2])
	{
		ft_swap(a);
		ft_rotate(a, 1);
	}
}