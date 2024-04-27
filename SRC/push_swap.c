/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/04/27 23:52:25 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_twod_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	free_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (a->numbers)
		free(a->numbers);
	if (b->numbers)
		free(b->numbers);
	if (a->tab)
		free(a->tab);
	if (b->tab)
		free(b->tab);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_sumilate_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit(1);
		if (ft_twod_len(argv) == 1 && !ft_isnumber(argv[0]))
		{
			free_argv(argv);
			ft_usage(NULL, NULL);
		}
		if (!init_stack(a, b, ft_twod_len(argv), argv) || ft_checks(argv))
		{
			free_argv(argv);
			ft_usage(a, b);
		}
		free_argv(argv);
	}
	else if (!init_stack(a, b, argc - 1, ++argv) || ft_checks(argv))
		ft_usage(a, b);
	if (!ft_positive_tab(a))
		ft_usage(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	ft_sumilate_args(argc, argv, &stack_a, &stack_b);
	if (ft_is_sorted(&stack_a))
		return (0);
	if (stack_a.size == 1)
		return (0);
	else if (stack_a.size == 2)
		ft_swap(&stack_a);
	else if (stack_a.size == 3)
		ft_sort3(&stack_a);
	else if (stack_a.size <= 5)
		ft_sort_5_and_4(&stack_a, &stack_b);
	else
	{
		ft_quicksort(&stack_a, &stack_b);
		ft_sort3(&stack_a);
		ft_b_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a, &stack_b);
	return (0);
}
