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
// int	ft_check_dup(char **array)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (array[i])
// 	{
// 		j = i + 1;
// 		while (array[j])
// 		{
// 			if (ft_strcmp(array[i], array[j]) == 1)
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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
		if (ft_isdigit(arg[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (arg[i])
// 	{
// 		j = 0;
// 		while (arg[i][j])
// 		{
// 			if (arg[i][j] == '-' || arg[i][j] == '+')
// 				j++;
// 			if (ft_isdigit(arg[i][j]) != 1)
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
