/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors_argc_is_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:30:37 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/17 20:04:37 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*create_list_argc_is_2(char **argv)
{
	char			**array;
	t_list			*lst;
	int				i;
	long int		nb;
	t_list			*new_node;

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
	free_array(array);
	return (lst);
}

static void	check_spaces_argc_is_2(char **argv)
{
	size_t	i;

	i = 0;
	if (argv[1][0] == 32 || argv[1][ft_strlen(argv[1]) - 1] == 32)
		return (write_error(), exit(1));
	while (i < ft_strlen(argv[1]))
	{
		if (argv[1][i] == 32 && i != ft_strlen(argv[1] - 1)
			&& argv[1][i + 1] == 32)
			return (write_error(), exit(1));
		i++;
	}
}

static void	check_sign_argc_is_2(char **argv)
{
	size_t	i;

	i = 0;
	if (ft_strlen(argv[1]) == 0)
		return (write_error(), exit(1));
	if (argv[1][ft_strlen(argv[1]) - 1] == '-')
		return (write_error(), exit(1));
	while (i < ft_strlen(argv[1]))
	{
		if (i > 0 && argv[1][i] == '-' && argv[1][i - 1] != 32)
			return (write_error(), exit(1));
		if (argv[1][i] == '-' && i != ft_strlen(argv[1] - 1)
			&& argv[1][i + 1] == '-')
			return (write_error(), exit(1));
		if (argv[1][i] == '-' && ft_isdigit(argv[1][i + 1]) == 0)
			return (write_error(), exit(1));
		i++;
	}
}

static void	is_a_number_argc_is_2(char **argv)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(argv[1]))
	{
		if (ft_isdigit((int)argv[1][i]) == 0 && argv[1][i] != '-'
			&& argv[1][i] != ' ')
		{
			return (write_error(), exit(1));
		}
		i++;
	}
}

void	manage_error_argc_is_2(char **argv)
{
	t_list	*stack_a;

	check_spaces_argc_is_2(argv);
	check_sign_argc_is_2(argv);
	is_a_number_argc_is_2(argv);
	stack_a = create_list_argc_is_2(argv);
	if (!stack_a)
		return (exit(1));
	two_same_numbers(stack_a);
	check_if_int(stack_a);
	check_u_long_max(argv);
	if (sorted_check(stack_a) == 1)
		exit(0);
	ft_lstclear(&stack_a);
}
