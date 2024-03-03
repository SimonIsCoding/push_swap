/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:42:20 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 20:32:04 by simarcha         ###   ########.fr       */
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
//			write(1, "ici\n", 4);
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
//	write(1, "1\n", 2);
	is_a_number(argc, argv);
//	write(1, "2\n", 2);
	stack_a = create_list(argc, argv);
	if (!stack_a)
		exit(1);
//	write(1, "3\n", 2);
	two_same_numbers(stack_a);
	check_if_int(stack_a);
//	write(1, "4\n", 2);
	sorted_check(stack_a);
	if (sorted_check(stack_a) == 1)
	{
//		write(1, "numbers are sorted\n", 19);
		exit(0);
	}
//	write(1, "end manage_error\n", 17);
	ft_lstclear(&stack_a);
//	printf("numbers not sorted => we can sort them\n");
//	printf("Well written\n");
}
