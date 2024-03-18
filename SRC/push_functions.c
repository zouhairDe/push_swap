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

void	ft_push(t_stack *from, t_stack *to)//from == b and to ==a hia push a || pa
{
	//khasni npushi mn from l to gher ra9m lwl
	//khasni fach npushi mn stack l stack nreallocer bach n9s blasa w nzid blasa w mannsach size tahia n9sha wla nzidha
	if (to->id == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}