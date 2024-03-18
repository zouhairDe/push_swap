/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:38:13 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 02:52:35 by zouddach         ###   ########.fr       */
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

void	ft_rotate(t_stack *stack, int code)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->numbers[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[i] = tmp;
	if (code != 0)
	{
		if (stack->id == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	return ;
}

void	ft_rotate_rev(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->numbers[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[i] = tmp;
	if (stack->id == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	return ;
}

void	ft_rerotates(t_stack *a, t_stack *b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	write(1, "rr\n", 3);
}