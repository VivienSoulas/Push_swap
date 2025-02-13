/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:13:14 by vsoulas           #+#    #+#             */
/*   Updated: 2025/02/13 17:42:02 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack is loaded with last arg input = top of stack;
int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc <= 1)
		return (ft_printf("Error\n"), EXIT_FAILURE);
	else if (argc == 2)
	{
		if (ft_string_to_stack(argv, &stack_a, 1) == 1)
			return (EXIT_FAILURE);
	}
	else
	{
		if (ft_arg_to_stack(argv, &stack_a) == 1)
			return (EXIT_FAILURE);
	}
	if (ft_check_dup(&stack_a) == 1)
		return (ft_free_stack(&stack_a), ft_printf("Error\n"), 1);
	ft_reverse_stack(&stack_a);
	if (ft_check_list(&stack_a) == 1)
		ft_sort(&stack_a);

/*===================================*/
ft_printf("\n|!| final stack |!|\n");
ft_print_stack(&stack_a);
/*===================================*/

	ft_free_stack(&stack_a);
	return (EXIT_SUCCESS);
}

int	ft_string_to_stack(char **argv, t_stack **head, int i)
{
	char	**array;
	int		j;

	array = ft_split(argv[i], ' ');
	if (array == NULL)
		return (1);
	j = 0;
	while (array[j])
	{
		if (ft_check_arg(array[j]) == 1)
		{
			ft_free_split(array);
			return (ft_printf("Error\n"), 1);
		}
		if (ft_add_to_stack(head, array[j]) == 1)
		{
			ft_free_split(array);
			ft_free_stack(head);
			return (1);
		}
		j++;
	}
	ft_free_split(array);
	return (0);
}

int	ft_arg_to_stack(char **argv, t_stack **head)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_search(argv[i], ' ') == 1)
		{
			if (ft_string_to_stack(argv, head, i) == 1)
				return (1);
		}
		else
		{
			if (ft_check_arg(argv[i]) == 1)
			{
				ft_free_stack(head);
				ft_printf("Error\n");
				return (EXIT_FAILURE);
			}
			if (ft_add_to_stack(head, argv[i]) == 1)
				return (ft_free_stack(head), 1);
		}
		i++;
	}
	return (0);
}

int	ft_add_to_stack(t_stack **head, char *arg)
{
	t_stack	*new_node;
	int		error;
	int		keys;

	error = 0;
	keys = 0;
	ft_atoi_flag(arg, &error, &keys);
	if (error == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (ft_free_stack(head), 1);
	new_node->content = ft_atoi_flag(arg, &error, &keys);
	new_node->keys = keys;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (0);
}
