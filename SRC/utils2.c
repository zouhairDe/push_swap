/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:35:59 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/12 17:55:32 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_all_digit(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

long	ft_atoi(char *str, t_stack *a, t_stack *b)
{
	long	nbr;
	char	sign;

	nbr = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (!ft_is_all_digit(str))
		ft_usage(NULL, NULL);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0') * sign;
		str++;
	}
	if (((*str < '0' || *str > '9') && *str != '\0')
		|| (nbr > 2147483647 || nbr < -2147483648))
		ft_usage(a, b);
	return (nbr);
}

static int	ft_get_smallest(t_stack *a, int number)
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
	while (i < a->size)
	{
		a->tab[i] = ft_get_smallest(a, a->numbers[i]);
		i++;
	}
	free(a->numbers);
	a->numbers = NULL;
	return (1);
}
