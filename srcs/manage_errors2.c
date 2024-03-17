/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:42:20 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/13 19:24:56 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//we want to create a function that write error for this nb 18446744073709551615
void	check_u_long_max(char **argv)
{
	int	is_zero;
	int	i;
	int	j;

	i = 1;
	is_zero = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == '0')
		{
			j++;
			is_zero++;
		}
		while (argv[i][j])
			j++;
		if (j - is_zero > 11)
			return (write_error(), exit(1));
		i++;
	}
}

void	check_if_int(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->nb > 2147483647 || tmp->nb < -2147483648)
			return (ft_lstclear(&lst), lst = NULL, write_error(), exit(1));
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
	check_u_long_max(argv);
	if (sorted_check(stack_a) == 1)
		exit(0);
	ft_lstclear(&stack_a);
}
