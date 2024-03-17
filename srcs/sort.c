/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:43:56 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/13 19:29:56 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_2_numbers(t_list **lst)
{
	swap_a(lst);
}

//Supposing that the numbers are not sorted
//this functions will sort 3 numbers in ascending order
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
}
