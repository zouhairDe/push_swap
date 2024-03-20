/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/20 10:45:02 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_usage(void)
{
	fprintf(stderr, "Error\n");
	exit(1);
}

int	ft_twod_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	return (i);
}

void	free_stack(t_stack *a, t_stack *b)
{
	if (a->numbers)
		free(a->numbers);
	if (b->numbers)
		free(b->numbers);
	if (a->tab)
		free(a->tab);
	if (b->tab)
		free(b->tab);
}

void	ft_sumilate_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');   //khasni nfree
		if (!argv)
			exit(1);
		if (!init_stack(a, b, ft_twod_len(argv), argv))
			(fprintf(stderr, "Error\n"), exit(1));
	}
	else if (!init_stack(a, b, argc - 1, ++argv))
		(fprintf(stderr, "Error\n"), exit(1));
	if (ft_checks(argv))
		ft_usage();
	ft_positive_tab(a);
	
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
	else
	{
		ft_quicksort(&stack_a, &stack_b);
		ft_sort3(&stack_a);
		ft_b_to_a(&stack_a, &stack_b);
	}
	free_stack(&stack_a, &stack_b);
	return (0);
}
//nafs ra9m 2 mrat not supported