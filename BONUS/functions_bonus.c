/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:38:13 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/25 01:35:06 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
	return ;
}

void	ft_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->tab[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp;
	return ;
}

void	ft_rotate_rev(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->tab[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[i] = tmp;
	return ;
}

void	ft_rerotate_rev(t_stack *a, t_stack *b)
{
	ft_rotate_rev(a);
	ft_rotate_rev(b);
}

void	ft_rerotate(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}
