/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:44:12 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/07 20:16:10 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a, int size_a)
{
	int	temp;

	if (!size_a || size_a == 1)
		return ;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(int *stack_b, int size_b)
{
	int	temp;

	if (!size_b || size_b == 1)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	temp;

	if (size_b <= 1 || (!size_a || size_a == 1))
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_putstr_fd("ss\n", 1);
}

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (!(*size_b))
		return ;
	i = *size_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*size_b - 1] = 0;
	(*size_a)++;
	(*size_b)--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (!(*size_a))
		return ;
	i = *size_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[*size_a - 1] = 0;
	(*size_a)--;
	(*size_b)++;
	ft_putstr_fd("pb\n", 1);
}
