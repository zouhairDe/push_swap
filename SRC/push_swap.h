/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:31:16 by zouddach          #+#    #+#             */
/*   Updated: 2024/04/27 23:52:44 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	id;
	int	*numbers;
	int	*tab;
	int	size;
}	t_stack;

typedef struct s_pivot
{
	int	first_pivot;
	int	sec_pivot;
	int	last_pivot;
}	t_pivot;

int		init_stack(t_stack *a, t_stack *b, int argc, char **argv);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_is_sorted(t_stack *a);
int		ft_checks(char **argv);
int		ft_positive_tab(t_stack *a);
int		ft_larger_than(char *str, char *max);
void	ft_quicksort(t_stack *a, t_stack *b);
void	ft_b_to_a(t_stack *a, t_stack *b);
void	ft_usage(t_stack *a, t_stack *b);
int		ft_isnumber(char *str);
char	**ft_split(char *str, char c);
size_t	ft_strlen(const char *str);
//Sorting functions here
void	ft_sort3(t_stack *a); //sorts 3 numbers
void	ft_sort_5_and_4(t_stack *a, t_stack *b); //sorts 5 or 4 numbers
void	ft_swap(t_stack *stack); //stands for sa || sb
void	ft_rotate(t_stack *stack, int code); // stands for ra || rb
void	ft_rerotate(t_stack *a, t_stack *b); //stands for rr
void	ft_rotate_rev(t_stack *stack, int code); // stands for rra || rrb
void	ft_rerotate_rev(t_stack *a, t_stack *b); //stands for rrr
int		ft_push(t_stack *from, t_stack *to); // stands for pa || pb
#endif