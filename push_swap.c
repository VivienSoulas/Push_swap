#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc <= 1)
	{
		ft_printf("Error: nor enough arg\n");
		return (EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		if (ft_string_to_stack(argv, &stack_a, 0) == 1)
			return (EXIT_FAILURE);
	}
	else
	{
		if (ft_arg_to_stack(argv, &stack_a) == 1)
			return (EXIT_FAILURE);
	}
	if (ft_check_dup(&stack_a) == 1)
		return(ft_free_stack(&stack_a), 1);
	ft_sort(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}

int	ft_string_to_stack(char **argv, t_stack **head, int i)
{
	char	**array;

	array = ft_split(argv[1], ' ');
	if (array == NULL)
		return (1);
	while (array[i])
	{
		ft_printf("string\n");
		if (ft_check_arg(array[i]) == 1)
		{
			ft_free_split(array);
			return (1);
		}
		if (ft_add_to_stack(head, array[i]) == 1)
		{
			ft_free_split(array);
			ft_free_stack(head);
			return (1);
		}
		i++;
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
		ft_printf("arg %i\n", i);
		if (ft_search(argv[i], ' ') == 1)
		{
			if (ft_string_to_stack(argv, head, i) == 1)
				return (1);
		}
		else
		{
			if (ft_check_arg(argv[i]) == 1)
			{
				ft_printf("Error: check arg\n");
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

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (ft_free_stack(head), 1);
	new_node->content = ft_atoi(arg);
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head == NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (0);
}
