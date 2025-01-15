/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:17:42 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/15 12:21:06 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sa : swap the values of the two elements at
the top of stack_a*/
void	sa_2(int *stack_a, int size_a)
{
	int	temp;

	if (!size_a || size_a == 1)
		return ;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}

/*sb : swap the values of the two elements at
the top of stack_b*/
void	sb_2(int *stack_b, int size_b)
{
	int	temp;

	if (!size_b || size_b == 1)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
}

/*applies sa and sb in one single operation*/
void	ss_2(int *stack_a, int *stack_b, int size_a, int size_b)
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
}

/*pa : pushes the top element of stack_b to stack_a
(and thus, shifts all the elements of stack_a
to the right and also shifts all the elements 
of stack_b to the left)*/
void	pa_2(int *stack_a, int *stack_b, int *size_a, int *size_b)
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
}

/*pb : pushes the top element of stack_a to stack_b
(and thus, shifts all the elements of stack_b
to the right and also shifts all the elements 
of stack_a to the left)*/
void	pb_2(int *stack_a, int *stack_b, int *size_a, int *size_b)
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
}
