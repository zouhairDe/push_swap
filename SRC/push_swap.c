/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/18 01:48:20 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_usage(void)
{
	printf("Error:\nUsage: ./push_swap [numbers]\n");
	exit(1);
}

void	ft_debug(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("Size of stack A:%d\nStack A numbers are:\n", a->size);
	while (i < a->size)
	{
		printf("%d\n", a->numbers[i]);
		i++;
	}
	i = 0;
	printf("Size of stack B:%d\nStack B numbers are:\n", b->size);
	while (i < b->size)
	{
		printf("%d\n", b->numbers[i]);
		i++;
	}
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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2 || ft_checks(argv))
		ft_usage();
	if (ft_is_sorted(argv, argc))
		exit(EXIT_FAILURE);
	if (!init_stack(&stack_a, &stack_b, argc, argv))
		(fprintf(stderr, "Error\n"), exit(1));
	// ft_debug(&stack_a, &stack_b);
	if (stack_a.size == 2)
		ft_swap(&stack_a);
	else if (stack_a.size == 3)
		ft_sort3(&stack_a);
	else
	{
		ft_positive_tab(&stack_a);
		ft_quicksort(&stack_a, &stack_b);
	}
	// printf("\n\nThe numbers are sorted\n\n");
	// ft_debug(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
//nafs ra9m 2 mrat not supported