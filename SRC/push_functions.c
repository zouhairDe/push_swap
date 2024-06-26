/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:00:11 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/12 18:26:39 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checks2(char **argv, t_stack *a, t_stack *b)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_countwords(argv[i], ' ') == 0)
			ft_usage(a, b);
		args = ft_split(argv[i], ' ');
		if (!args)
		{
			ft_free_stack(a, b);
			exit(1);
		}
		while (args[j])
		{
			ft_add_to_stack(a, ft_atoi(args[j], a, b));
			j++;
		}
		free_argv(args);
		i++;
	}
}

static int	ft_realloc_stack(t_stack *from, t_stack *to,
int **tmp_from, int **tmp_to)
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

static int	ft_maintain_stack(t_stack *from, t_stack *to)
{
	int	*tmp_from;
	int	*tmp_to;
	int	i;

	if (from->size == 0)
		return (1);
	if (ft_realloc_stack(from, to, &tmp_from, &tmp_to))
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

int	ft_push(t_stack *from, t_stack *to)
{
	if (ft_maintain_stack(from, to))
		ft_usage(from, to);
	if (to->id == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return (0);
}
