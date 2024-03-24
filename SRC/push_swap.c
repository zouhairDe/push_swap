/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/24 17:07:17 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_twod_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
		return (0);//to handle later ila kan hi ra9m wahd
	return (i);
}

void	free_stack(t_stack *a, t_stack *b, char **argv, int argc)
{
	int i = 0;
	if (a->numbers)
		free(a->numbers);
	if (b->numbers)
		free(b->numbers);
	if (a->tab)
		free(a->tab);
	if (b->tab)
		free(b->tab);
}

void	free_argv(char **argv, int len)
{
	int i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_sumilate_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	int i;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit(1);
		if (!init_stack(a, b, ft_twod_len(argv), argv) || ft_checks(argv))
		{
			free_argv(argv, ft_twod_len(argv));
			ft_usage(a, b);
		}
		free_argv(argv, ft_twod_len(argv));
	}
	else if (!init_stack(a, b, argc - 1, ++argv) || ft_checks(argv))
		ft_usage(a, b);
	if (!ft_positive_tab(a))
		ft_usage(a, b);
}

// void	f(void)
// {
// 	system("leaks push_swap");
// }

int	main(int argc, char **argv)
{
	// atexit(f);
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
	else
	{
		ft_quicksort(&stack_a, &stack_b);
		ft_sort3(&stack_a);
		ft_b_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a, &stack_b, argv, argc);
	return (0);
}