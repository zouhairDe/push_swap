/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:38:13 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/17 23:01:42 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->numbers[0];
	stack->numbers[0] = stack->numbers[1];
	stack->numbers[1] = tmp;
	if (stack->id == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return ;
}