/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:12:56 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:34:43 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks for duplicates in the list
int	ft_check_dup(t_stack **head)
{
	t_stack	*current;
	t_stack	*checker;

	current = *head;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

// checks double array argv for multiple '+' or '-'
// checks for non digits
int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) != 1 || arg[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

// check that list is sorted
int	ft_check_list(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}
