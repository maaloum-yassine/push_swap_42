/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:25:30 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 00:16:01 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_range(t_stack *stack_a)
{
	return (stack_a->len_ar * 0.0525 + 13.75);
}

static void	ft_move(t_stack *stack_a, t_stack *stack_b, t_range *range, int ref)
{
	if (ref < range->start)
	{
		ft_push(stack_a, stack_b, 'b');
		ft_rotate(stack_b, stack_a, 'b');
		range->start++;
		range->end++;
	}
	else if (ref >= range->start && ref <= range->end)
	{
		ft_push(stack_a, stack_b, 'b');
		range->start++;
		range->end++;
	}
	else
		ft_rotate(stack_a, stack_b, 'a');
}

void	ft_first_step(t_stack *stack_a, t_stack *stack_b)
{
	t_range	range;
	int		lenght;
	int		*array_ref;
	int		ref;

	lenght = stack_a->len_ar;
	range.start = 0;
	range.end = ft_get_range(stack_a);
	array_ref = ft_sort_array(stack_a);
	while (stack_a->len_ar)
	{
		ref = get_ref(array_ref, stack_a->ar_int[0], lenght);
		ft_move(stack_a, stack_b, &range, ref);
	}
	free (array_ref);
}

static int	ft_get_max(t_stack *stack_b)
{
	int	i;
	int	max;

	i = 1;
	max = stack_b->ar_int[0];
	while (i < stack_b->len_ar)
	{
		if (max < stack_b->ar_int[i])
			max = stack_b->ar_int[i];
			i++;
	}
	return (max);
}

void	ft_last_step(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	index;

	while (stack_b->len_ar != 0)
	{
		max = ft_get_max(stack_b);
		index = get_index(stack_b, max);
		while (stack_b->ar_int[0] != max)
		{
			if (index >= stack_b->len_ar / 2)
				ft_reverse(stack_b, stack_a, 'b');
			else
				ft_rotate(stack_b, stack_a, 'b');
		}
		ft_push(stack_b, stack_a, 'a');
	}
}
