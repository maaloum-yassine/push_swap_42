/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:08:47 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 00:15:32 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_check_descending(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->len_ar)
	{
		j = i + 1;
		while (j < stack_a->len_ar)
		{
			if (stack_a->ar_int[i] < stack_a->ar_int[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	ft_sort_arg_descending(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len_ar)
	{
		ft_push(stack_a, stack_b, 'b');
		ft_rotate(stack_b, stack_a, 'b');
	}
	while (stack_b->len_ar)
		ft_push(stack_b, stack_a, 'b');
}

static int	*remplir_array(t_stack *stack_a)
{
	int	*sort_array;
	int	i;

	sort_array = malloc(sizeof(int) * stack_a->len_ar);
	ft_protect_malloc(sort_array, stack_a->ar_int, NULL);
	i = 0;
	while (i < stack_a->len_ar)
	{
		sort_array[i] = stack_a->ar_int[i];
		i++;
	}
	return (sort_array);
}

int	*ft_sort_array(t_stack *stack_a)
{
	int	i;
	int	j;
	int	*sort_array;
	int	tmp;

	sort_array = remplir_array(stack_a);
	i = 0;
	j = 0;
	while (i < stack_a->len_ar)
	{
		j = i + 1;
		while (j < stack_a->len_ar)
		{
			if (sort_array[j] < sort_array[i])
			{
				tmp = sort_array[j];
				sort_array[j] = sort_array[i];
				sort_array[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sort_array);
}

int	get_ref(int *array, int top_number, int lenght)
{
	int	ref;

	ref = 0;
	while (ref < lenght)
	{
		if (top_number == array[ref])
			break ;
		ref++;
	}
	return (ref);
}
