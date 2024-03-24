/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:23:13 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/24 17:05:25 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_free_all(t_stack *a, t_stack *b)
{
	if (a->numbers)
		free(a->numbers);
	if (b->numbers)
		free(b->numbers);
	if (a->tab)
		free(a->tab);
	if (b->tab)
		free(b->tab);
	exit(1);
}

void	ft_usage(t_stack *a, t_stack *b)
{
	fprintf(stderr, "Error\n");
	if (a != NULL && b != NULL)
		ft_free_all(a, b);
}