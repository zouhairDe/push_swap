/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:38:13 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/17 01:43:55 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
	if (stack->id == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return ;
}