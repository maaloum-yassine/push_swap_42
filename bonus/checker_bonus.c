/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:31:31 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 05:05:32 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] - s2[i] == 0)
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_check_move(t_stack *stack_a, t_stack *stack_b, char *get_str)
{
	if (ft_strcmp(get_str, "sa\n") == 0)
		ft_swap(stack_a, stack_b, 'a');
	else if (ft_strcmp(get_str, "sb\n") == 0)
		ft_swap(stack_a, stack_b, 'b');
	else if (ft_strcmp(get_str, "ss\n") == 0)
		ft_swap(stack_a, stack_b, 's');
	else if (ft_strcmp(get_str, "pa\n") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(get_str, "pb\n") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(get_str, "ra\n") == 0)
		ft_rotate(stack_a, stack_b, 'a');
	else if (ft_strcmp(get_str, "rb\n") == 0)
		ft_rotate(stack_b, stack_a, 'b');
	else if (ft_strcmp(get_str, "rr\n") == 0)
		ft_rotate(stack_a, stack_b, 'r');
	else if (ft_strcmp(get_str, "rra\n") == 0)
		ft_reverse(stack_a, stack_b, 'a');
	else if (ft_strcmp(get_str, "rrb\n") == 0)
		ft_reverse(stack_b, stack_a, 'b');
	else if (ft_strcmp(get_str, "rrr\n") == 0)
		ft_reverse(stack_a, stack_b, 'r');
	else
		ft_error(stack_a, stack_b, get_str);
}

static int	check_array_is_sort(int *array_int, int lenght_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < lenght_array)
	{
		j = i + 1;
		while (j < lenght_array)
		{
			if (array_int[i] < array_int[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*get_str;

	get_str = get_next_line(0);
	while (get_str)
	{
		ft_check_move(stack_a, stack_b, get_str);
		ft_free(NULL, NULL, get_str);
		get_str = get_next_line(0);
	}
	if (check_array_is_sort(stack_a->ar_int, stack_a->len_ar) == 0
		&& stack_b->len_ar == 0)
	{
		write(1, "OK\n", 3);
		ft_free(stack_a->ar_int, stack_b->ar_int, get_str);
		exit(0);
	}
	else
	{
		write(2, "KO\n", 3);
		ft_free(stack_a->ar_int, stack_b->ar_int, get_str);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*str;
	char	**str_split;

	if (ac > 1)
	{
		stack_a.ar_int = NULL;
		stack_b.ar_int = NULL;
		stack_b.len_ar = 0;
		str = fusionner_arg_value(av);
		str_split = ft_split(str, ' ');
		stack_a.len_ar = ft_lenght_word(str, ' ');
		if (ft_check_str_split_isdigit(str_split) == 0)
			ft_put_error();
		ft_remplir_array_int(str_split, &stack_a);
		ft_check_array(&stack_a);
		ft_checker(&stack_a, &stack_b);
	}
	return (0);
}
