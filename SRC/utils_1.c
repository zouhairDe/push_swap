/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:43:21 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/11 19:06:55 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_add_to_stack(t_stack *a, int value)
{
	int	*new_tab;
	int	i;

	new_tab = malloc(sizeof(int) * (a->size + 1));
	if (!new_tab)
		return (0);
	i = 0;
	while (a->numbers && i < a->size)
	{
		new_tab[i] = a->numbers[i];
		i++;
	}
	new_tab[i] = value;
	free(a->numbers);
	a->numbers = new_tab;
	a->size++;
	return (1);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == ' ');
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	else
	{
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	if (i == 0)
		return (0);
	return (1);
}

void	ft_init_structs(t_stack *a, t_stack *b)
{
	a->id = 1;
	a->size = 0;
	a->tab = NULL;
	a->numbers = NULL;
	b->id = 2;
	b->size = 0;
	b->tab = NULL;
	b->numbers = NULL;
}

int	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_add_to_stack(a, ft_atoi(argv[i], a, b)))
			return (0);
		i++;
	}
	return (1);
}
