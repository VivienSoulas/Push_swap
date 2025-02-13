/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:13:25 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:41:00 by vsoulas          ###   ########.fr       */
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
int	ft_atoi_flag(char *str, int *error, int *keys)
{
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	if (str[*keys] == '-')
	{
		sign *= -1;
		(*keys)++;
	}
	else if (str[*keys] == '+')
		(*keys)++;
	while (str[*keys])
	{
		number = number * 10 + (str[*keys] - '0');
		if (number * sign > INT_MAX || number * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		(*keys)++;
	}
	return (number * sign);
}

int	ft_max(t_stack **head)
{
	t_stack	*current;
	int		max;

	max = INT_MIN;
	current = *head;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
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