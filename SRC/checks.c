/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:28:18 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/20 10:34:21 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	int	i;

	i = a->size - 1;
	while (i > 0)
	{
		if (a->tab[i] < a->tab[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	ft_is_duplicate(char	**argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				fprintf(stderr, "Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_biger_than_ints(char **argv)
{
    int	i;
    int	j;

    i = 0;
    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
        {
            if (argv[i][j++] == '-')
            {
                if (ft_larger_than(&argv[i][j], "2147483648"))
                    return (0);
            }
            else
                if (ft_larger_than(&argv[i][j], "2147483647"))
                    return (0);
        }
        else
            if (ft_larger_than(&argv[i][j], "2147483647"))
                return (0);
        i++;
    }
    return (1);
}

int ft_checks(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				(fprintf(stderr, "Error\n"), exit(1));
			j++;
		}
		i++;
	}
	ft_is_duplicate(argv);
	if (!ft_is_biger_than_ints(argv))
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	return (0);
}
