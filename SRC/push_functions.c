/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:00:11 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 22:56:45 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fr_reallocate_stack(t_stack *from, t_stack *to, int **tmp_from, int **tmp_to)
{
	*tmp_from = (int *)malloc(sizeof(int) * (from->size - 1));
	if (!tmp_from)
		return (1);
	*tmp_to = (int *)malloc(sizeof(int) * (to->size + 1));
	if (!tmp_to)
	{
		free(tmp_from);
		return (1);
	}
	return (0);
}

int	ft_maintain_stack(t_stack *from, t_stack *to)
{
	int *tmp_from;
	int *tmp_to;
	int i;

	if(fr_reallocate_stack(from, to, &tmp_from, &tmp_to))
		return (1);
	i = -1;
	while (++i < from->size - 1)
		tmp_from[i] = from->tab[i + 1];
	i = -1;
	while (++i < to->size)
		tmp_to[i + 1] = to->tab[i];
	tmp_to[0] = from->tab[0];
	free(from->tab);
	free(to->tab);
	from->tab = tmp_from;
	to->tab = tmp_to;
	from->size--;
	to->size++;
	return (0);
}

void	ft_push(t_stack *from, t_stack *to)//from == b and to ==a hia push a || pa
{
	//khasni npushi mn from l to gher ra9m lwl                                                                             √
	//khasni fach npushi mn stack l stack nreallocer bach n9s blasa w nzid blasa w mannsach size tahia n9sha wla nzidha    √
	if (ft_maintain_stack(from, to))
		return ;//hna khasni tkhrj
	if (to->id == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}