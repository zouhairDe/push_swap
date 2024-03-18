/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:35:59 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 22:59:28 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		i;
	long	n;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int	ft_get_smallest(t_stack *a, int number)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < a->size)
	{
		if (a->numbers[i] < number)
			j++;
		i++;
	}
	return (j);
}

int	ft_positive_tab(t_stack *a)
{
	int	i;

	i = 0;
	a->tab = (int *)malloc(sizeof(int) * a->size);
	if (!a->tab)
		return (0);
	while(i < a->size)
	{
		a->tab[i] = ft_get_smallest(a, a->numbers[i]);
		i++;
	}
	free(a->numbers);
	a->numbers = NULL;
	return (1);
}