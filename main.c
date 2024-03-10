/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:53:45 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/10 20:38:41 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void imprimerNumeros(int liste1[], int liste2[], int taille); 

//we want a function to convert the args passed by the user into nodes
//then we will create a list with these numbers
t_list	*create_list(int argc, char **argv)
{
	t_list			*lst;
	int				i;
	long int		nb;
	t_list			*new_node;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		new_node = ft_lstnew(nb, i - 1);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
//	t_list	*tmp_a;
//	t_list	*tmp_b;
	int		i;
//	t_list	*min_pc;
//	int		median;

	i = 0;
	manage_error(argc, argv);
	stack_b = NULL;
//	if (argc < 2)
//		return (1);
	if (argc == 2)
		stack_a = create_list_argc_is_2(argv);
	else
		stack_a = create_list(argc, argv);
	if (ft_lstsize(stack_a) == 2)
		sort_2_numbers(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_3_numbers(&stack_a);
	else
	{
//		swap_first_last(&stack_a);
//		the_reverse_rotate(stack_a);
//		push_b(&stack_a, &stack_b);
//		push_b(&stack_a, &stack_b);
//		push_b(&stack_a, &stack_b);
//		push_b(&stack_a, &stack_b);
//		push_b(&stack_a, &stack_b);
//		push_b(&stack_a, &stack_b);
//		tmp_a = stack_a;
//		tmp_b = stack_b;
//		algorithm(&stack_a, &stack_b);
//		move_the_closest_smaller(stack_a, stack_b);
//		find_target_node_a(stack_a, stack_b);
//		find_target_node_b(stack_b, stack_a);
//		rate_single_cost(stack_a);
//		rate_single_cost(stack_b);
//		push_cost_total(stack_a);
//		push_cost_total(stack_b);
//		min_pc = min_push_cost(&stack_a);
//		median = calculate_median(stack_a);	
//		median = find_median(&stack_a);
//		printf("median : %i\n", median);

		char **array = array_numbers(stack_a);
		int	x = 0;
		while (array[x])	
		{
			printf("%s\n", array[x]);
			x++;
		}
		printf("min = %i\n", find_min(array));
		printf("median = %i\n", find_the_median(array, ft_lstsize(stack_a), 0));
		free_array(array);
		printf("move node in B\n");
		move_node_in_B(&stack_a, &stack_b);
	}
 
	printf("lstsize of stack A = %i\n", ft_lstsize(stack_a));
	printf("lstsize of stack B = %i\n", ft_lstsize(stack_b));
	printf("the min of the stack a is: (%li:%u)\n", min_list_nb(&stack_a)->nb, min_list_nb(&stack_a)->index);
	printf("the max of the stack a is: (%li:%u)\n", max_list_nb(&stack_a)->nb, max_list_nb(&stack_a)->index);
//	printf("the min of the stack b is: (%li:%u)\n", min_list_nb(&stack_b)->nb, min_list_nb(&stack_b)->index);
//	printf("the max of the stack b is: (%li:%u)\n", max_list_nb(&stack_b)->nb, max_list_nb(&stack_b)->index);

	printf("-------------       -------------\n");
	printf("|  STACK A  |       |  STACK B  |\n");
	printf("-------------	    -------------\n");
	printf("  nb  :index          nb  :index\n");
	print_list(stack_a, stack_b);

//	printf("------------------------------\n");
//	printf("current_node is : (%li,%i)\n", stack_a->nb, stack_a->index);
/*	while (stack_a)
	{
		printf("stack_a: node_%i->target->nb: %li && single_cost : %i\n", i, stack_a->target->nb, stack_a->single_cost);
		printf("stack_a: nb %li && push_cost : %i\n", stack_a->nb, stack_a->push_cost);
		printf("------\n");
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	while (stack_b)
	{
		printf("stack_b: node_%i->target->nb: %li && single_cost : %i\n", i, stack_b->target->nb, stack_b->single_cost);
		printf("stack_b: nb %li && push_cost : %i\n", stack_b->nb, stack_b->push_cost);
		printf("------\n");
		stack_b = stack_b->next;
		i++;
	}
	printf("minimal push_cost for stack a: %i\n", min_pc->push_cost);*/
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
