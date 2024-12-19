/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:57:36 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/19 18:03:03 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_num(char *str)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		cpt++;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (cpt);
}

int	is_sorted(int ac, char **av, int *stack_a)
{
	int	i;
	char **av_cpy;
	int size;

	if (ac == 2)
	{
		av_cpy = ft_split(av[1], ' ');
		i = 0;
		size = count_num(av[1]) - 1;
	}
	else
	{
		av_cpy = av;
		i = 1;
		size = ac - 1;
	}
	while (i < size)
	{
		if (ft_atoi(av_cpy[i], stack_a) > ft_atoi(av_cpy[i + 1], stack_a))
			return (0);
		i++;
	}
	return (1);
}
