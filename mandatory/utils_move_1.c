/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:42:09 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 03:24:42 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_stack(t_stack *stack)
{
	int	swap;

	swap = stack->ar_int[0];
	stack->ar_int[0] = stack->ar_int[1];
	stack->ar_int[1] = swap;
}

void	ft_swap(t_stack *stack_a, t_stack *stack_b, char mouve)
{
	if (mouve == 'a')
	{
		if (stack_a->len_ar >= 2)
		{
			ft_swap_stack(stack_a);
			write(1, "sa\n", 3);
		}
	}
	else if (mouve == 'b')
	{
		if (stack_b->len_ar >= 2)
		{
			ft_swap_stack(stack_b);
			write(1, "sb\n", 3);
		}
	}
	else if (mouve == 's')
	{
		if (stack_b->len_ar >= 2 && stack_b->len_ar >= 2)
		{
			ft_swap_stack(stack_a);
			ft_swap_stack(stack_b);
			write(1, "ss\n", 3);
		}
	}
}

static void	ft_print_push(char mouve)
{
	if (mouve == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

static void	ft_modification_stack(t_stack *stack_from,
		t_stack *stack_into, char mouve)
{
	t_s_var	tools;
	int		i;
	int		j;

	i = 1;
	j = 0;
	tools.ar_tmp = malloc(sizeof(int) * (--stack_from->len_ar));
	ft_protect_malloc(tools.ar_tmp, stack_from->ar_int, stack_into->ar_int);
	while (j < stack_from->len_ar)
	tools.ar_tmp[stack_from->len_ar - 1 - j++] = stack_from->ar_int[i++];
	free (stack_from->ar_int);
	stack_from->ar_int = malloc(sizeof(int) * (stack_from->len_ar));
	ft_protect_malloc(stack_from->ar_int, stack_into->ar_int, tools.ar_tmp);
	i = 0;
	j = 0;
	while (i < stack_from->len_ar)
		stack_from->ar_int[stack_from->len_ar - 1 - i++] = tools.ar_tmp[j++];
	free (tools.ar_tmp);
	ft_print_push(mouve);
}

void	ft_push(t_stack *stack_from, t_stack *stack_into, char mouve)
{
	t_s_var	tools;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (stack_from->len_ar != 0)
	{
		stack_into->len_ar++;
		tools.ar_tmp = malloc(sizeof(int) * stack_into->len_ar);
		ft_protect_malloc(tools.ar_tmp, stack_from->ar_int, stack_into->ar_int);
		while (i < stack_into->len_ar)
		tools.ar_tmp[stack_into->len_ar - 1 - i++] = stack_into->ar_int[j++];
		tools.ar_tmp[stack_into->len_ar - 1] = stack_from->ar_int[0];
		free (stack_into->ar_int);
		stack_into->ar_int = malloc(sizeof(int) * stack_into->len_ar);
		ft_protect_malloc(stack_into->ar_int, tools.ar_tmp, stack_from->ar_int);
		i = 0;
		j = 0;
		while (i < stack_into->len_ar)
		stack_into->ar_int[stack_into->len_ar - 1 - i++] = tools.ar_tmp[j++];
		free (tools.ar_tmp);
		ft_modification_stack(stack_from, stack_into, mouve);
	}
}
