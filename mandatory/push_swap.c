/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 06:41:00 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 05:27:48 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_check_descending(stack_a) == true)
		ft_sort_arg_descending(stack_a, stack_b);
	else
	{
		ft_first_step(stack_a, stack_b);
		ft_last_step(stack_a, stack_b);
	}
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len_ar == 2)
		ft_sort_2arg(stack_a);
	else if (stack_a->len_ar == 3)
		ft_sort_3arg(stack_a, stack_b);
	else if (stack_a->len_ar == 4)
		ft_sort_4arg(stack_a, stack_b);
	else if (stack_a->len_ar == 5)
		ft_sort_5arg(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*str;
	char		**str_split;

	if (ac > 1)
	{
		stack_b.len_ar = 0;
		stack_b.ar_int = NULL;
		stack_a.ar_int = NULL;
		str = fusionner_arg_value(av);
		str_split = ft_split(str, ' ');
		stack_a.len_ar = ft_lenght_word(str, ' ');
		free(str);
		if (ft_check_str_split_isdigit(str_split) == 0)
			ft_put_error();
		ft_remplir_array_int(str_split, &stack_a);
		ft_check_array(&stack_a);
		ft_sort_stack(&stack_a, &stack_b);
		free(stack_a.ar_int);
		free(stack_b.ar_int);
	}
	return (0);
}
