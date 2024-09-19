/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:43:13 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 03:56:22 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3arg(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->ar_int[0] > stack_a->ar_int[1]
		&& stack_a->ar_int[0] > stack_a->ar_int[2]
		&& stack_a->ar_int[1] < stack_a->ar_int[2])
		ft_rotate(stack_a, stack_b, 'a');
	else if (stack_a->ar_int[0] > stack_a->ar_int[1]
		&& stack_a->ar_int[0] > stack_a->ar_int[2]
		&& stack_a->ar_int[1] > stack_a->ar_int[2])
	{
		ft_rotate(stack_a, stack_b, 'a');
		ft_swap(stack_a, stack_b, 'a');
	}
	else if (stack_a->ar_int[0] > stack_a->ar_int[1]
		&& stack_a->ar_int[0] < stack_a->ar_int[2]
		&& stack_a->ar_int[1] < stack_a->ar_int[2])
		ft_swap(stack_a, stack_b, 'a');
	else if (stack_a->ar_int[0] < stack_a->ar_int[1]
		&& stack_a->ar_int[0] > stack_a->ar_int[2]
		&& stack_a->ar_int[1] > stack_a->ar_int[2])
		ft_reverse(stack_a, stack_b, 'a');
	else if (stack_a->ar_int[2] < stack_a->ar_int[1]
		&& stack_a->ar_int[2] > stack_a->ar_int[0])
	{
		ft_reverse(stack_a, stack_b, 'a');
		ft_swap(stack_a, stack_b, 'a');
	}
}

int	get_min_num(t_stack *stack_a)
{
	int	i;
	int	min;

	i = 1;
	min = stack_a->ar_int[0];
	while (i < stack_a->len_ar)
	{
		if (min > stack_a->ar_int[i])
		min = stack_a->ar_int[i];
		i++;
	}
	return (min);
}

int	get_index(t_stack *stack_a, int number)
{
	int	i;

	i = 0;
	while (i < stack_a->len_ar)
	{
		if (number == stack_a->ar_int[i])
			break ;
		i++;
	}
	return (i);
}

static void	ft_sort_4(t_stack *stack_a, t_stack *stack_b, int index)
{
	if (index == 0)
	{
		ft_push(stack_a, stack_b, 'b');
		ft_sort_3arg(stack_a, stack_b);
		ft_push(stack_b, stack_a, 'a');
	}
	else if (index == 1)
	{
		ft_rotate(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
		ft_sort_3arg(stack_a, stack_b);
		ft_push(stack_b, stack_a, 'a');
	}
	else if (index == 2)
	{
		ft_rotate(stack_a, stack_b, 'a');
		ft_rotate(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
		ft_sort_3arg(stack_a, stack_b);
		ft_push(stack_b, stack_a, 'a');
	}
}

void	ft_sort_4arg(t_stack *stack_a, t_stack *stack_b)
{
	int	min ;
	int	index;

	min = get_min_num(stack_a);
	index = get_index(stack_a, min);
	if (index >= 0 && index <= 2)
		ft_sort_4(stack_a, stack_b, index);
	else
	{
		ft_reverse(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'b');
		ft_sort_3arg(stack_a, stack_b);
		ft_push(stack_b, stack_a, 'a');
	}
}
