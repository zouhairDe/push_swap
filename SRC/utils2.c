/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:35:59 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/24 16:39:14 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_all_digit(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_larger_than(char *str, char *max)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(max);
	while (*str == '0')
		str++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
		i++;
	if (i > len)
		return (1);
	else if (i < len)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (*str > *max)
			return (1);
		else if (*str++ < *max++)
			return (0);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		nbr;
	char	sign;

	nbr = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (!ft_is_all_digit(str))
		ft_usage(NULL, NULL);
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
		{
			sign = -1;
			if (ft_larger_than(str, "2147483648"))
				return (-1);
		}
		else
			if (ft_larger_than(str, "2147483647"))
				return (-1);
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0') * sign;
		str++;
	}
	return (nbr);
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