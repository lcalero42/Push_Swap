/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:44:12 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/13 12:24:34 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a, int size_a)
{
	int	temp;

	if (!size_a || size_a == 1)
		return ;
	temp = stack_a[size_a - 1];
	stack_a[size_a - 1] = stack_a[size_a - 2];
	stack_a[size_a - 2] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(int *stack_b, int size_b)
{
	int	temp;

	if (!size_b || size_b == 1)
		return ;
	temp = stack_b[size_b - 1];
	stack_b[size_b - 1] = stack_b[size_b - 2];
	stack_b[size_b - 2] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	temp;

	if (!(size_b || size_b == 1) || (!size_a || size_a == 1))
		return ;
	temp = stack_b[size_b - 1];
	stack_b[size_b - 1] = stack_b[size_b - 2];
	stack_b[size_b - 2] = temp;
	temp = stack_a[size_a - 1];
	stack_a[size_a - 1] = stack_a[size_a - 2];
	stack_a[size_a - 2] = temp;
	ft_putstr_fd("ss\n", 1);
}

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (!(*size_b))
		return ;
	stack_a[*size_a - 1] = stack_b[*size_b - 1];
	(*size_a)++;
	(*size_b)--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (!(*size_a))
		return ;
	stack_b[*size_b - 1] = stack_a[*size_a - 1];
	(*size_b)++;
	(*size_a)--;
	ft_putstr_fd("pb\n", 1);
}
