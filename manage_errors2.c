/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:42:20 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/01 18:09:41 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list_argc_is_2(char **argv)
{
	char	**array;
	t_list	*lst;
	int		i;
	int		nb;
	t_list	*new_node;

	i = 0;
	lst = NULL;
	array = ft_split(argv[1], ' ');
	while (array[i])
	{
		nb = ft_atol(array[i]);
		new_node = ft_lstnew(nb, i);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

void	argc_is_2(char **argv)
{
	int		i;
	t_list	*lst;

	i = 0;
	while (argv[1][i] != '\0' && (size_t)i < ft_strlen(*argv) - 1)
	{
		if ((argv[1][i] == 32 && argv[1][i + 1] == 32)
				|| (argv[1][ft_strlen(argv[1]) - 1] == 32 || argv[1][0] == 32))
			return (write_error(), exit(1));
		if (!(ft_isdigit((int)argv[1][i]) == 1 || (argv[1][i] == 32)))
			return (write_error(), exit(1));
		i++;
	}
	lst = create_list_argc_is_2(argv);
	if (!lst)
		return (exit(1));
	two_same_numbers(lst);
	sorted_check(lst);
	if (sorted_check(lst) == 1)
	{
//		printf("numbers are sorted\n");
		exit(0);
	}
//	printf("numbers not sorted => we can sort them\n");
//	printf("Well written\n");
}

void	manage_error(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 2)
	{
		argc_is_2(argv);
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
//	write(1, "4\n", 2);
	sorted_check(stack_a);
	if (sorted_check(stack_a) == 1)
	{
		write(1, "numbers are sorted\n", 19);
		exit(0);
	}
//	write(1, "end manage_error\n", 17);
	ft_lstclear(&stack_a);
//	printf("numbers not sorted => we can sort them\n");
//	printf("Well written\n");
}
