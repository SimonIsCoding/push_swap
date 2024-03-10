/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:13:04 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/10 20:47:11 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node_in_B(t_list **stack_a, t_list **stack_b)
{
	int		median_value;
	char	**array;

	array = array_numbers(*stack_a);//you have to free it after using it
	median_value = find_the_median(array, ft_lstsize(*stack_a), 0);
	free_array(array);
	while (ft_lstsize(*stack_a) > 3)
	{
		push_b(stack_a, stack_b);
		if (ft_lstsize(*stack_b) > 1)
			if ((*stack_b)->nb > median_value)
				reverse_rotate_b(stack_b);
	}
	sort_3_numbers(stack_a);
	print_list(*stack_a, *stack_b);	
}
