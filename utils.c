#include "push_swap.h"

t_stack	*ft_last_node(t_stack *head)
{
	if (head)
	{
		while (head->next != NULL)
			head = head->next;
	}
	return (head);
}

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
