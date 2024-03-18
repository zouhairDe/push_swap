/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:00:11 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 03:01:33 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to, int code)
{
	int	i;

	if (from->size == 0)
		return ;
	i = to->size;
	while (i > 0)
	{
		to->numbers[i] = to->numbers[i - 1];
		i--;
	}
	to->numbers[0] = from->numbers[0];
	i = 0;
	while (i < from->size - 1)
	{
		from->numbers[i] = from->numbers[i + 1];
		i++;
	}
	from->size--;
	to->size++;
	if (code == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}