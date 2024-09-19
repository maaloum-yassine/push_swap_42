/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:26:38 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 03:29:27 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			ft_swap_stack(stack_a);
	}
	else if (mouve == 'b')
	{
		if (stack_b->len_ar >= 2)
			ft_swap_stack(stack_b);
	}
	else if (mouve == 's')
	{
		if (stack_b->len_ar >= 2 && stack_b->len_ar >= 2)
		{
			ft_swap_stack(stack_a);
			ft_swap_stack(stack_b);
		}
	}
}

static void	ft_modification_stack(t_stack *stack_from, t_stack *stack_into)
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
}

void	ft_push(t_stack *stack_from, t_stack *stack_into)
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
		ft_modification_stack(stack_from, stack_into);
	}
}
