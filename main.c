/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:53:45 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/02 19:38:12 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	manage_error(argc, argv);
	stack_b = NULL;
	if (argc == 2)
		stack_a = create_list_argc_is_2(argv);
	else
		stack_a = create_list(argc, argv);

	printf("the min of the stack a is: (%li:%u)\n", min_list(&stack_a)->nb, min_list(&stack_a)->index);
	printf("the max of the stack a is: (%li:%u)\n", max_list(&stack_a)->nb, max_list(&stack_a)->index);
	printf("-------------       -------------\n");
	printf("|  STACK A  |       |  STACK B  |\n");
	printf("-------------	    -------------\n");
	printf("  nb : index         nb : index\n");
	print_list(stack_a, stack_b);
	printf("\n");
	printf("-------------\n");

	if (ft_lstsize(stack_a) == 2)
		sort_2_numbers(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_3_numbers(&stack_a);
/*	else if (ft_lstsize(stack_a) == 4)
		sort_4_numbers(&stack_a);

	else
		sort(&stack_a);
*/
	printf("-------------\n");
	printf("\n");
	printf("-------------       -------------\n");
	printf("|  STACK A  |       |  STACK B  |\n");
	printf("-------------	    -------------\n");
	printf("  nb : index         nb : index\n");
	print_list(stack_a, stack_b);


//	reverse_rotate_a(&stack_a);
//	swap_a(&stack_a);
//	push_b(&stack_a, &stack_b);
//	push_b(&stack_a, &stack_b);
//	swap_b(&stack_b);
//	rotate_a_and_b(&stack_a, &stack_b);
//	swap_a_and_b(&stack_a, &stack_b);
//	swap_b(&stack_b);
//	reverse_rotate_b(&stack_b);
//	reverse_rotate_a(&stack_a);
//	reverse_rotate_a_and_b(&stack_a, &stack_b);
//	rotate_b(&stack_b);
//	rotate_b(&stack_b);
//	rotate_a(&stack_a);
//	rotate_a_and_b(&stack_a, &stack_b);
//	push_a(&stack_b, &stack_a);//WATCH OUT: THIS IS FROM B TO A => THE ORDER OF THE ARGUMENT MATTERS USING THIS FUNTCION
//	push_a(&stack_b, &stack_a);//WATCH OUT: THIS IS FROM B TO A => THE ORDER OF THE ARGUMENT MATTERS USING THIS FUNTCION
//	reverse_rotate_a(&stack_a);
//	swap_a(&stack_a);
//	push_b(&stack_a, &stack_b);
//	push_b(&stack_a, &stack_b);
//	swap_b(&stack_b);
//	rotate_a_and_b(&stack_a, &stack_b);
//	swap_a_and_b(&stack_a, &stack_b);
//	swap_b(&stack_b);
//	reverse_rotate_b(&stack_b);
//	reverse_rotate_a(&stack_a);
//	reverse_rotate_a_and_b(&stack_a, &stack_b);
//	rotate_b(&stack_b);
//	rotate_b(&stack_b);
//	rotate_a(&stack_a);
//	rotate_a_and_b(&stack_a, &stack_b);
//	push_a(&stack_b, &stack_a);//WATCH OUT: THIS IS FROM B TO A => THE ORDER OF THE ARGUMENT MATTERS USING THIS FUNTCION
//	push_a(&stack_b, &stack_a);//WATCH OUT: THIS IS FROM B TO A => THE ORDER OF THE ARGUMENT MATTERS USING THIS FUNTCION

	ft_lstclear(&stack_a);
	return (0);
}

/*    // Libération de la mémoire allouée pour la liste
    while (head != NULL) {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }
*/
