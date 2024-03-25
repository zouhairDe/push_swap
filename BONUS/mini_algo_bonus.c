/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:59:14 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/25 02:02:13 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*_s1;
	unsigned char	*_s2;

	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	while (*_s1 && *_s2 && (*_s1 == *_s2))
	{
		_s1++;
		_s2++;
	}
	return (*_s1 - *_s2);
}

void	ft_sswap(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_apply_instruction(t_stack *a, t_stack *b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		ft_swap(a);
	else if (!ft_strcmp(instruction, "sb\n"))
		ft_swap(b);
	else if (!ft_strcmp(instruction, "ss\n"))
		ft_sswap(a, b);
	else if (!ft_strcmp(instruction, "pa\n"))
		ft_push(b, a);
	else if (!ft_strcmp(instruction, "pb\n"))
		ft_push(a, b);
	else if (!ft_strcmp(instruction, "ra\n"))
		ft_rotate(a);
	else if (!ft_strcmp(instruction, "rb\n"))
		ft_rotate(b);
	else if (!ft_strcmp(instruction, "rr\n"))
		ft_rerotate(a, b);
	else if (!ft_strcmp(instruction, "rra\n"))
		ft_rotate_rev(a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		ft_rotate_rev(b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		ft_rerotate_rev(a, b);
	else
		ft_usage(a, b);
}

void	ft_get_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		ft_apply_instruction(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return ;
}
