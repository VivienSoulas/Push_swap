/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:01:37 by vsoulas           #+#    #+#             */
/*   Updated: 2024/10/28 11:17:05 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include <limits.h>
// #include <stdio.h>

// int	ft_atoi(const char *nptr);

// int	main(void)
// {
//     const char *test_str = "2147483648986"; // INT_MAX + 1
//     printf("Result: %d\n", ft_atoi(test_str));
//     return (0);
// }

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}
