/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:53:45 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/13 18:14:09 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//we want a function to convert the args passed by the user into nodes
//then we will create a list with these numbers
t_list	*create_list(int argc, char **argv)
{
	t_list			*lst;
	int				i;
	long int		nb;
	t_list			*new_node;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		new_node = ft_lstnew(nb, i - 1);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	manage_error(argc, argv);
	stack_b = NULL;
	if (argc == 2)
		stack_a = create_list_argc_is_2(argv);
	else
		stack_a = create_list(argc, argv);
	if (ft_lstsize(stack_a) == 2)
		sort_2_numbers(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_3_numbers(&stack_a);
	else
		big_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
