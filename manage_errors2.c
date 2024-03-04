/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:42:20 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/03 12:30:21 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_int(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->nb > 2147483647 || tmp->nb < -2147483648)
		{
			return (ft_lstclear(&lst), lst = NULL, write_error(), exit(1));
		}
		tmp = tmp->next;
	}
}

void	manage_error(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 2)
	{
		manage_error_argc_is_2(argv);
		return ;
	}
	is_a_number(argc, argv);
	stack_a = create_list(argc, argv);
	if (!stack_a)
		exit(1);
	two_same_numbers(stack_a);
	check_if_int(stack_a);
//	sorted_check(stack_a);
	if (sorted_check(stack_a) == 1)
	{
		//I don't understand why I don't have leaks here. I should have it
		//I should free the list here to avoid leaks before exit.
		//but I don't have leaks
		exit(0);
	}
	ft_lstclear(&stack_a);
}
