/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:31:05 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 02:37:52 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**ft_split(char *str, char sep)
{
	char	**s;
	int		i;
	int		j;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	s = malloc (sizeof(char *) * (ft_lenght_word(str, sep) + 1));
	if (!s)
		exit(1);
	while (str[i])
	{
		while (str[j] == sep && str[j])
			j++;
		i = j;
		while (str[j] != sep && str[j])
			j++;
		if (i != j)
			s[index++] = ft_sub_str(str, i, j - i);
		i = j;
	}
	s[index] = NULL;
	return (s);
}

void	ft_put_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	ft_free_strplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static int	ft_str_split_isnot_digit(char **str)
{
	ft_free_strplit(str);
	return (0);
}

int	ft_check_str_split_isdigit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (!str[i][j])
			return (ft_str_split_isnot_digit(str));
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (ft_str_split_isnot_digit(str));
			j++;
		}
		i++;
	}
	return (1);
}
