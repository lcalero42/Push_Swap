/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:57:36 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/06 11:20:45 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static int	count_num(char *str)
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
}*/

int	is_sorted(int *stack_a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
