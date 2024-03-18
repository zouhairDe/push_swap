/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:00:11 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 03:06:51 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *from, t_stack *to, int code)//from == b and to ==a hia push a || pa
{
	//khasni npushi mn from l to gher ra9m lwl
	if (from->id == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}