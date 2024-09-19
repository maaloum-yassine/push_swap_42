/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:27:16 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 04:57:49 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_protect_malloc(int *array_a, int *array_b, int *array_c)
{
	if (!array_a)
	{
		free (array_b);
		free (array_c);
		write(2, "ERROR MALLOC HEAP\n", 18);
		exit(1);
	}
}

static void	ft_reverse_rotate(t_stack *stack_used, t_stack *stack_second)
{
	t_s_var	tools;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tools.ar_tmp = malloc((stack_used->len_ar - 1) * sizeof(int));
	ft_protect_malloc(tools.ar_tmp, stack_used->ar_int, stack_second->ar_int);
	while (i < stack_used->len_ar - 1)
	tools.ar_tmp[stack_used->len_ar - 2 - i++] = stack_used->ar_int[j++];
	tools.var = stack_used->ar_int[stack_used->len_ar - 1];
	free (stack_used->ar_int);
	stack_used->ar_int = malloc(sizeof(int) * stack_used->len_ar);
	ft_protect_malloc(stack_used->ar_int, tools.ar_tmp, stack_second->ar_int);
	i = 0;
	j = 0;
	while (i < stack_used->len_ar - 1)
	stack_used->ar_int[stack_used->len_ar - 1 - i++] = tools.ar_tmp[j++];
	free (tools.ar_tmp);
	stack_used->ar_int[0] = tools.var;
}

void	ft_reverse(t_stack *stack_used, t_stack *stack_second, char mouve)
{
	if (mouve == 'a')
	{
		if (stack_used->len_ar)
			ft_reverse_rotate(stack_used, stack_second);
	}
	else if (mouve == 'b')
	{
		if (stack_used->len_ar)
			ft_reverse_rotate(stack_used, stack_second);
	}
	else if (mouve == 'r')
	{
		if (stack_used->len_ar && stack_second->len_ar)
		{
			ft_reverse_rotate(stack_used, stack_second);
			ft_reverse_rotate(stack_second, stack_used);
		}
	}
}

static void	ft_rotate_stack(t_stack *stack_used, t_stack *stack_second)
{
	t_s_var	tools;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tools.ar_tmp = malloc((stack_used->len_ar - 1) * sizeof(int));
	ft_protect_malloc(tools.ar_tmp, stack_used->ar_int, stack_second->ar_int);
	tools.var = stack_used->ar_int[0];
	while (i < stack_used->len_ar - 1)
		tools.ar_tmp[i++] = stack_used->ar_int[++j];
	free (stack_used->ar_int);
	stack_used->ar_int = malloc(stack_used->len_ar * sizeof(int));
	ft_protect_malloc(stack_used->ar_int, stack_second->ar_int, tools.ar_tmp);
	stack_used->ar_int[stack_used->len_ar - 1] = tools.var;
	i = 0;
	j = 0;
	while (i < stack_used->len_ar - 1)
	stack_used->ar_int[i++] = tools.ar_tmp[j++];
	free(tools.ar_tmp);
}

void	ft_rotate(t_stack *stack_used, t_stack *stack_second, char mouve)
{
	if (mouve == 'a')
	{
		if (stack_used->len_ar)
			ft_rotate_stack(stack_used, stack_second);
	}
	else if (mouve == 'b')
	{
		if (stack_used->len_ar)
			ft_rotate_stack(stack_used, stack_second);
	}
	else if (mouve == 'r')
	{
		if (stack_used->len_ar && stack_second->len_ar)
		{
			ft_rotate_stack(stack_used, stack_second);
			ft_rotate_stack(stack_second, stack_second);
		}
	}
}
