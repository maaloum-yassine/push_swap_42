/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:40:15 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 05:29:04 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free(int *stack_a, int *stack_b, char *get_str)
{
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);
	if (get_str != NULL )
		free(get_str);
}

void	ft_error(t_stack *stack_a, t_stack *stack_b, char *get_str)
{
	ft_free(stack_a->ar_int, stack_b->ar_int, get_str);
	ft_put_error();
}
