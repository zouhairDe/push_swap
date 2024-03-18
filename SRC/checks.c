/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:28:18 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 01:32:24 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(char **args, int argc)
{
	int	i;

	i = argc - 1;
	while (i > 1)
	{
		if (ft_atoi(args[i]) < ft_atoi(args[i - 1]))
			return (0);
		i--;
	}
	printf("The numbers you provided are already sorted\n");
	return (1);
}

int	ft_is_duplicate(char	**argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				printf("Error:\nYou have duplicate numbers\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int ft_checks(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (ft_is_duplicate(argv))
		return (1);
	return (0);
}
