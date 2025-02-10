#include "push_swap.h"

void	ft_sort(t_stack **head)
{
	int		i;
	t_stack	*current;

	current = *head;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	if (i == 2)
		ft_sort_2(head);
	ft_print_stack(head);
}

void	ft_sort_2(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	next = current->next;
	if (current->content == next->content)
	{
		ft_one_up(head, 'a');
	}
}

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
