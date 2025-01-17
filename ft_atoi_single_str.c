/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_single_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:30:37 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/17 14:45:35 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	ft_atoi_single_str(const char *nptr, int *stack_a, char **av, int size)
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
			return (ft_free(av, size), print_error_free(stack_a), 0);
		i++;
	}
	return ((int)res * sign);
}
