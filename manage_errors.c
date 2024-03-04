/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:02:32 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/03 13:02:01 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(void)
{
	return (write(1, "Error\n", 6));//WATCH OUT IF YOUR WRITE FAILS
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

//we want to create a function to check if it's not a number
void	is_a_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit((int)argv[i][j]) == 0 && argv[i][j] != '-')
			{
				return (write_error(), exit(1));
			}
			j++;
		}
		i++;
	}
}

//we have to return an error if we have two same numbers
void	two_same_numbers(t_list *lst)
{
	t_list	*tmp;
	int		check;

	check = 0;
	while (lst != NULL)
	{
		tmp = lst;
		check = 0;
		while (tmp != NULL)
		{
			if (tmp->nb == lst->nb)
				check++;
			tmp = tmp->next;
		}
		if (check > 1)
			return (ft_lstclear(&lst), lst = NULL, write_error(), exit(1));
		lst = lst->next;
	}
}

//This functions checks if the number are already sorted. 
int	sorted_check(t_list	*lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
