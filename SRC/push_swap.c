/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/12 18:26:05 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_stack(t_stack *a, t_stack *b)
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
	return (1);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static void	ft_sumilate_args(char **argv, t_stack *a, t_stack *b)
{
	if (ft_checks(argv))
		ft_usage(NULL, NULL);
	ft_checks2(argv, a, b);
	if (ft_is_duplicate(a->numbers, a->size))
		ft_usage(a, b);
	if (!ft_positive_tab(a))
		ft_usage(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	ft_init_structs(&stack_a, &stack_b);
	ft_sumilate_args(argv, &stack_a, &stack_b);
	if (ft_is_sorted(&stack_a))
		return (ft_free_stack(&stack_a, &stack_b));
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
	ft_free_stack(&stack_a, &stack_b);
	return (0);
}
