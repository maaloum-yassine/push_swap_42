/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 06:59:58 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/02/24 00:09:38 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_av(char *av, int *lenght)
{
	int	i;

	i = 0;
	while (av[i] == ' ' && av[i])
		i++;
	if (i == *lenght)
		ft_put_error();
}

static int	ft_lenght_av(char **av)
{
	int	j;
	int	i;
	int	lenght;

	i = 1;
	lenght = 0;
	while (av[i])
	{
		j = 0;
		if (!av[i][0])
			ft_put_error();
		while (av[i][j])
		{
			lenght++;
			j++;
		}
		ft_check_av(av[i], &j);
		if (av[i + 1])
			lenght++;
		i++;
	}
	return (lenght);
}

char	*fusionner_arg_value(char **av)
{
	int		lenghtstr;
	char	*str;
	int		j;
	int		i;
	int		x;

	i = 1;
	x = 0;
	lenghtstr = ft_lenght_av(av);
	str = malloc(lenghtstr + 1);
	if (!str)
	{
		write(2, "ERROR MALLOC HEAP\n", 18);
		exit(0);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			str[x++] = av[i][j++];
		str[x++] = ' ';
		i++;
	}
	str[lenghtstr] = '\0';
	return (str);
}

char	*ft_sub_str(char *str, int start, int len)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(len + 1);
	if (!s)
	{
		write(2, "ERROR MALLOC HEAP\n", 18);
		exit(0);
	}
	while (i < len)
		s[i++] = str[start++];
	s[len] = '\0';
	return (s);
}

int	ft_lenght_word(char *str, char sep)
{
	int	i;
	int	check;
	int	word;

	i = 0;
	check = 0;
	word = 0;
	while (str[i])
	{
		check = 0;
		while (str[i] == sep && str[i])
			i++;
		while (str[i] != sep && str[i])
		{
			i++;
			check = 1;
		}
		if (check == 1)
			word++;
	}
	return (word);
}
