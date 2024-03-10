/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:43:56 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/08 20:00:43 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This functions checks if the number are sorted in the reverse order.
int	reverse_sorted_check(t_list	*lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->next->nb > tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_2_numbers(t_list **lst)
{
	swap_a(lst);
//	exit(0);
}

void	sort_3_numbers(t_list **lst)
{
	if (min_list_nb(lst)->index == 1)
	{
		if (max_list_nb(lst)->index == 0)
			rotate_a(lst);
		else
			swap_a(lst);
	}
	else if (max_list_nb(lst)->index == 1)
	{
		if (min_list_nb(lst)->index == 2)
			reverse_rotate_a(lst);
		else
		{
			reverse_rotate_a(lst);
			swap_a(lst);
		}
	}
	else
	{
		rotate_a(lst);
		swap_a(lst);
	}
//	exit(0);
}
