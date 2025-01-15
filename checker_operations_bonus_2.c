/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_bonus_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:32 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/15 12:20:44 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ra : shifts all the elements to the left
and the first element becomes the last in 
stack_a*/
void	ra_2(int *stack_a, int size_a)
{
	int	i;
	int	first;

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
}

/*rb : shifts all the elements to the left
and the first element becomes the last in 
stack_b*/
void	rb_2(int *stack_b, int size_b)
{
	int	i;
	int	first;

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
}

/*applies ra and rb in one operation*/
void	rr_2(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;
	int	first;

	if (size_a <= 1 || size_b <= 1)
		return ;
	i = 0;
	first = stack_a[0];
	while (i < size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size_a - 1] = first;
	i = 0;
	first = stack_b[0];
	while (i < size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size_b - 1] = first;
}

/*rra : shifts all the elements to the right
and the last element becomes the first in stack_a*/
void	rra_2(int *stack_a, int size_a)
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
}

/*rrb : shifts all the elements to the right
and the last element becomes the first in stack_b*/
void	rrb_2(int *stack_b, int size_b)
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
}
