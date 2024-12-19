/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:37:23 by lcalero           #+#    #+#             */
/*   Updated: 2024/12/19 18:00:32 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"
#include "stdio.h"
#include "../push_swap.h"

int	ft_atoi(const char *nptr, int *stack_a)
{
	size_t	i;
	long	res;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && res * -1 < INT_MIN))
			print_error_free(stack_a);
		i++;
	}
	return ((int)res * sign);
}
