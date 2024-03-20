/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:14 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/20 03:14:37 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack *a)
{
	if (a->tab[0] > a->tab[1] && a->tab[0] < a->tab[2])
		ft_swap(a);
	else if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		ft_rotate_rev(a, 1);
	else if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2])
		ft_rotate(a, 1);
	else if (a->tab[0] < a->tab[1] && a->tab[0] > a->tab[2])
		ft_rotate_rev(a, 1);
	else if (a->tab[0] < a->tab[1] && a->tab[0] < a->tab[2])
	{
		ft_swap(a);
		ft_rotate(a, 1);
	}
}