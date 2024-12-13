/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:29:26 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/13 12:12:18 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*stack_a;
	int	i;
	int	size_a;

	stack_a = parse_input(ac, av, &size_a);
	if (!stack_a)
		return (1);
	i = 0;
	printf("Before sa :\n\n\n");
	while (i < size_a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	i = 0;
	sa(stack_a, size_a);
	printf("After sa :\n\n\n");
	while (i < size_a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	free(stack_a);
	return (0);
}
