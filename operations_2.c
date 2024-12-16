/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:39:58 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/16 17:01:10 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *stack_a, int size_a)
{
	int	i;
	int	last;

	if (size_a <= 1)
		return ;
	i = 0;
	last = stack_a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = last;
	ft_putstr_fd("ra\n", 1);
}

void	rb(int *stack_b, int size_b)
{
	int	i;
	int	last;

	if (size_b <= 1)
		return ;
	i = 0;
	last = stack_b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last;
	ft_putstr_fd("rb\n", 1);
}

void	rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	last;

	if (size_a <= 1 || size_b <= 1)
		return ;
	i = 0;
	last = stack_a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = last;
	i = 0;
	last = stack_b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last;
	ft_putstr_fd("rr\n", 1);
}

void	rra(int *stack_a, int size_a)
{
	int	i;
	int first;

	if (size_a <= 1)
		return ;
	i = 0;
	first = stack_a[0];
	while (i < size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size_a - 1] = first;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(int *stack_b, int size_b)
{
	int	i;
	int first;

	if (size_b <= 1)
		return ;
	i = 0;
	first = stack_b[0];
	while (i < size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size_b - 1] = first;
	ft_putstr_fd("rrb\n", 1);
}
