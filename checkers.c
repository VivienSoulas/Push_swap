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
	t_stack	*next;

	current = *head;
	next = current->next;
	while (next)
	{
		if (current->content > next->content)
			return (1);
		next = next->next;
	}
	return (0);
}
