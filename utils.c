/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:13:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:04:15 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// implicitly names, find the last node of the stack
t_stack	*ft_last_node(t_stack *head)
{
	if (head)
	{
		while (head->next != NULL)
			head = head->next;
	}
	return (head);
}

// searching for ' ' within a string
int	ft_search(char *arg, char c)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// function to reverse the stack
void	ft_reverse_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*temp;

	current = *head;
	while (current)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		if (temp == NULL)
			*head = current;
		current = temp;
	}
}

// modified atoi to rule out above INT_MAX and bellow INT_MIN
int	ft_atoi_flag(char *str, int *error)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		number = number * 10 + (str[i] - '0');
		if (number * sign > INT_MAX || number * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return (number * sign);
}

/* =================================================================== */
void	ft_print_stack(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current)
	{
		ft_printf("%i\n", current->content);
		current = current->next;
	}
}
/* =================================================================== */