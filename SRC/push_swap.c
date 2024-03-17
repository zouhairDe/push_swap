/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:30:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/17 02:47:07 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}

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
	printf("Size of stack B:%d\nStack A numbers are:\n", b->size);
	while (i < b->size)
	{
		printf("%d\n", b->numbers[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2 || ft_checks(argv))
		ft_usage();
	if (!init_stack(&stack_a, &stack_b, argc, argv))
		(fprintf(stderr, "Error\n"), exit(1));
	ft_debug(&stack_a, &stack_b);
}
