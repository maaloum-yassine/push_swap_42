/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:58:21 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 04:15:40 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(char *str, int *array_int, char **str_split)
{
	int			i;
	int			signe;
	long int	res;

	i = 0;
	signe = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i++] - '0';
		if ((res * signe) > __INT32_MAX__ || (res * signe) < -2147483648)
		{
			ft_free_strplit(str_split);
			free (array_int);
			ft_put_error();
		}
	}
	return ((int)(res * signe));
}

void	ft_remplir_array_int(char **str_split, t_stack *s_a)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	s_a->ar_int = malloc(sizeof(int) * s_a->len_ar);
	if (!s_a->ar_int)
	{
		write(2, "ERROR MALLOC HEAP\n", 18);
		exit(1);
	}
	while (str_split[i])
		s_a->ar_int[x++] = ft_atoi(str_split[i++], s_a->ar_int, str_split);
	ft_free_strplit(str_split);
	if (s_a->len_ar == 1)
	{
		free(s_a->ar_int);
		exit(0);
	}
}

static int	ft_check_double_number(int *array_int, int lenght_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lenght_array)
	{
		j = i + 1;
		while (j < lenght_array)
		{
			if (array_int[i] == array_int[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

void	ft_check_array(t_stack *s_t_a)
{
	if (ft_check_double_number(s_t_a->ar_int, s_t_a->len_ar) == 0)
	{
		ft_put_error();
		free(s_t_a->ar_int);
	}
	if (check_array_is_sort(s_t_a->ar_int, s_t_a->len_ar) == 0)
	{
		free(s_t_a->ar_int);
		exit(0);
	}
}
