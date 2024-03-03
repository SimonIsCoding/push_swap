/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:43:56 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 19:37:45 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_numbers(t_list **lst)
{
	swap_a(lst);
//	exit(0);
}

void	sort_3_numbers(t_list **lst)
{
	if (min_list(lst)->index == 1)
	{
		if (max_list(lst)->index == 0)
			rotate_a(lst);
		else
			swap_a(lst);
	}
	else if (max_list(lst)->index == 1)
	{
		if (min_list(lst)->index == 2)
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

/*void	sort_4_numbers(t_list **lst)
{
	
}*/
