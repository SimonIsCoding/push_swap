/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:46:49 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/17 19:46:52 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//when every node will be sorted, we will need a function to move the smalles
//at the top
static void	move_min_at_top(t_list **stack_a)
{
	t_list	*min_node;
	int		middle_stack;

	middle_stack = ft_lstsize(*stack_a) / 2;
	min_node = min_list_nb(stack_a);
	while (min_node->index != 0)
	{
		if (min_node->index < middle_stack)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

//we want a function that do rrr or rr if needed instead of doing rra & rrb
static void	save_movement(t_list **stack_a, t_list **stack_b, t_list *min_pc)
{
	int	mid_stk_a;
	int	mid_stk_b;

	mid_stk_a = ft_lstsize(*stack_a) / 2;
	mid_stk_b = ft_lstsize(*stack_b) / 2;
	if (min_pc->index > mid_stk_b && min_pc->target->index > mid_stk_a)
		reverse_rotate_a_and_b(stack_a, stack_b);
	else if (min_pc->index < mid_stk_b && min_pc->target->index < mid_stk_a)
		rotate_a_and_b(stack_a, stack_b);
}

static void	finish_rotations(t_list **stack_a, t_list **stack_b, t_list *min_pc)
{
	int	mid_stk_a;
	int	mid_stk_b;

	mid_stk_a = ft_lstsize(*stack_a) / 2;
	mid_stk_b = ft_lstsize(*stack_b) / 2;
	while (min_pc->index != 0)
	{
		if (min_pc->index < mid_stk_b)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
	while (min_pc->target->index != 0)
	{
		if (min_pc->target->index < mid_stk_a)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

static void	move_node_in_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_pc;

	while (*stack_b)
	{
		find_target_node_b(*stack_b, *stack_a);
		rate_single_cost(*stack_a);
		rate_single_cost(*stack_b);
		push_cost_total(*stack_b);
		min_pc = min_push_cost(stack_b);
		if (min_pc->index != 0 && min_pc->target->index != 0)
			save_movement(stack_a, stack_b, min_pc);
		finish_rotations(stack_a, stack_b, min_pc);
		push_a(stack_b, stack_a);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		median_value;
	char	**array;

	array = array_numbers(*stack_a);
	median_value = find_the_median(array, ft_lstsize(*stack_a), 0);
	free_array(array);
	while (ft_lstsize(*stack_a) > 3)
	{
		push_b(stack_a, stack_b);
		if (ft_lstsize(*stack_b) > 1)
			if ((*stack_b)->nb > median_value)
				rotate_b(stack_b);
	}
	if (sorted_check(*stack_a) == 0)
		sort_3_numbers(stack_a);
	move_node_in_a(stack_a, stack_b);
	move_min_at_top(stack_a);
}
