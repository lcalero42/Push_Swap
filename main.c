/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:29:26 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/13 12:27:12 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	int	size_a;

	stack_a = parse_input(ac, av, &size_a);
	if (!stack_a)
		return (1);
	stack_b = malloc(size_a * sizeof(int));
	i = 0;
	ss(stack_a, stack_b, size_a, size_a);
	printf("a stack :\n");
	while (i < size_a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	printf("b stack :\n");
	i = 0;
	while (i < size_a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
