/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:44:45 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/10 09:45:21 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//what is the single_cost ?
//this is the movement we need to put the current node at the top of the stack
//what is the push_cost ?
//this is the minimum movement we need to execute to put the current node and 
//his target at the top of their stack.

//This function calculate the single push_cost for one node in the stack
void	rate_single_cost(t_list *stack)
{
	int	lstsize;
	int	median;

	lstsize = ft_lstsize(stack);
	median = lstsize / 2;
	while (stack)
	{
//		if (lstsize % 2 == 0)
//		{
			if (stack->index < median)
				stack->single_cost = stack->index;
			else
				stack->single_cost = stack->index - lstsize;
//		}
/*		else
		{
			if (stack->index < (median + 1))
			{
				stack->single_cost = stack->index;
			}
			else
				stack->single_cost = stack->index - lstsize ;
		}
*/		stack = stack->next;
	}
}

//function that choose the min between two numbers
static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

//function that choose the max between two numbers
static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

//this functions calculate the push_cost total. 
//It means the single cost of the current node + the single cost of his target
//If we do the same movements, we choose the number that costs more movements.
void	push_cost_total(t_list *stack)
{
	int	pc_total;

	while (stack)
	{
		pc_total = 0;
		if (stack->single_cost > 0 && stack->target->single_cost > 0)
			pc_total = ft_max(stack->single_cost, stack->target->single_cost);
		else if (stack->single_cost < 0 && stack->target->single_cost < 0)
			pc_total = ft_min(stack->single_cost, stack->target->single_cost);
		else
			pc_total = stack->single_cost - stack->target->single_cost;
		if (pc_total < 0)
			pc_total *= -1;
		stack->push_cost = pc_total;
		stack = stack->next;
	}
}
