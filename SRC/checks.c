/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   checks.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: zouddach <zouddach@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/18 01:28:18 by zouddach		  #+#	#+#			 */
/*   Updated: 2024/03/24 17:04:42 by zouddach		 ###   ########.fr	   */
/*																			*/
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

int	ft_is_duplicate(int *r, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (r[i] == r[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checks(char **argv)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!args)
			return (1);
		while (args[j])
		{
			if (!ft_isnumber(args[j]))
			{
				free_argv(args);
				return (1);
			}
			j++;
		}
		i++;
		free_argv(args);
	}
	return (0);
}
