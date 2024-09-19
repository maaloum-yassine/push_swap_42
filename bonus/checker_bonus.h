/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:38:14 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 04:11:28 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

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

char	*fusionner_arg_value(char **av);
char	*ft_sub_str(char *str, int start, int len);
int		ft_lenght_word(char *str, char sep);
char	**ft_split(char *str, char sep);
void	ft_put_error(void);
void	ft_free_strplit(char **str);
int		ft_check_str_split_isdigit(char **str);
void	ft_remplir_array_int(char **str_split, t_stack *s_tack_a);
int		ft_check_double_number(int *array_int, int lenght_array);
void	ft_check_array(t_stack *s_tack_a);
void	ft_protect_malloc(int *array_a, int *array_b, int *array_c);
void	ft_push(t_stack *stack_from, t_stack *stack_into);
void	ft_swap(t_stack *stack_used, t_stack *stack_second, char mouve);
void	ft_reverse(t_stack *stack_used, t_stack *stack_second, char mouve);
void	ft_rotate(t_stack *stack_used, t_stack *stack_second, char mouve);
void	ft_free(int *stack_a, int *stack_b, char *get_str);
void	ft_error(t_stack *stack_a, t_stack *stack_b, char *get_str);
#endif
