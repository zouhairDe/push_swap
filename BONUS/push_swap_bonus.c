/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/05 18:12:07 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_twod_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static void	ft_free_stack(t_stack *a, t_stack *b)
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

static void	free_argv(char **argv)
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

static void	ft_sumilate_args(int argc, char **argv, t_stack *a, t_stack *b)
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
		if (!ft_init_stack(a, b, ft_twod_len(argv), argv) || ft_checks(argv))
		{
			free_argv(argv);
			ft_usage(a, b);
		}
		free_argv(argv);
	}
	else if (!ft_init_stack(a, b, argc - 1, ++argv) || ft_checks(argv))
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
	ft_get_instructions(&stack_a, &stack_b);
	if (stack_a.size && ft_is_sorted(&stack_a))
	{
		write(1, "OK\n", 3);
		ft_free_stack(&stack_a, &stack_b);
		return (0);
	}
	write(1, "KO\n", 3);
	ft_free_stack(&stack_a, &stack_b);
	return (1);
}
//TODO: khasni nms7 ga3 l functions li mastakhdmtch f had l code
