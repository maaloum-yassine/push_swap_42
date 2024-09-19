/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:51:48 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 00:14:50 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2arg(t_stack *stack_used)
{
	if (stack_used->ar_int[0] > stack_used->ar_int[1])
		ft_swap(stack_used, NULL, 'a');
}

static void	push_min_num(t_stack *stack_a, t_stack *stack_b, int index)
{
	if (index == 0)
		ft_push(stack_a, stack_b, 'b');
	else if (index == 1)
	{
		ft_rotate(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else if (index == 2)
	{
		ft_rotate(stack_a, stack_b, 'a');
		ft_rotate(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else if (index == 3)
	{
		ft_rotate(stack_a, stack_b, 'a');
		ft_rotate(stack_a, stack_b, 'a');
		ft_rotate(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	else if (index == 4)
	{
		ft_reverse(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
}

void	ft_sort_5arg(t_stack *stack_a, t_stack *stack_b)
{
	int	min ;
	int	index;

	min = get_min_num(stack_a);
	index = get_index(stack_a, min);
	push_min_num(stack_a, stack_b, index);
	ft_sort_4arg(stack_a, stack_b);
	ft_push(stack_b, stack_a, 'a');
}
