/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:25:56 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/23 23:41:59 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int	*ar_int;
	int	len_ar;
}	t_stack;

typedef struct s_s_var
{
	int	*ar_tmp;
	int	var;
}	t_s_var;

typedef struct s_range
{
	int	start;
	int	end;
}	t_range;

char	*fusionner_arg_value(char **av);
char	*ft_sub_str(char *str, int start, int len);
int		ft_lenght_word(char *str, char sep);
char	**ft_split(char *str, char sep);
void	ft_put_error(void);
void	ft_free_strplit(char **str);
int		ft_check_str_split_isdigit(char **str);
void	ft_remplir_array_int(char **str_split, t_stack *s_a);
void	ft_check_array(t_stack *s_tack_a);
void	ft_protect_malloc(int *array_a, int *array_b, int *array_c);
void	ft_push(t_stack *stack_from, t_stack *stack_into, char mouve);
void	ft_swap(t_stack *stack_used, t_stack *stack_second, char mouve);
void	ft_reverse(t_stack *stack_used, t_stack *stack_second, char mouve);
void	ft_rotate(t_stack *stack_used, t_stack *stack_second, char mouve);
void	ft_sort_2arg(t_stack *stack_used);
void	ft_sort_3arg(t_stack *stack_a, t_stack *stack_b);
int		get_min_num(t_stack *stack_a);
int		get_index(t_stack *stack_a, int number);
void	ft_sort_4arg(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_5arg(t_stack *stack_a, t_stack *stack_b);
bool	ft_check_descending(t_stack *stack_a);
void	ft_sort_arg_descending(t_stack *stack_a, t_stack *stack_b);
int		*ft_sort_array(t_stack *stack_a);
int		get_ref(int *array, int top_number, int lenght);
void	ft_first_step(t_stack *stack_a, t_stack *stack_b);
void	ft_last_step(t_stack *stack_a, t_stack *stack_b);

#endif
