/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:53:45 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/01 18:04:42 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//we want a function to convert the args passed by the user into nodes
//then we will create a list with these numbers

t_list	*create_list(int argc, char **argv)
{
	t_list	*lst;
	int		i;
	int		nb;
	t_list	*new_node;

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
	stack_a = create_list(argc, argv);
	printf("A	B\n");
	printf("-	-\n");
	printf("nb:i	nb:i\n");
	print_list(stack_a, stack_b);

	printf("---------\n");
	printf("A	B\n");
	printf("-	-\n");
	printf("nb:i	nb:i\n");

//	reverse_rotate(&stack_a);
	swap(&stack_a);
//	push_b(&stack_a, &stack_b);
//	push_b(&stack_a, &stack_b);
//	swap(&stack_b);
//	reverse_rotate(&stack_b);

	print_list(stack_a, stack_b);

	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

/*    // Libération de la mémoire allouée pour la liste
    while (head != NULL) {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }
*/

/*void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;
	t_list	*tmp;

//	write(1, "Entered push_b_begin\n", 21);
//	printf("Entered push_b\n");	
	if (*stack_a == NULL) 
	{
		write(1, "useless movement\n", 17);
		return ;
	}
	first_a = *stack_a;
	first_a->prev = NULL;
	first_a->next = (*stack_a)->next;
	if ((*stack_a)->next)
	{
		second_a = (*stack_a)->next;
		second_a->prev = (*stack_a)->prev;


		*stack_a = second_a;
		second_a->prev = NULL;

		tmp = *stack_a;
		while (tmp != NULL)
		{
			tmp->index--;
			tmp = tmp->next;
		}
	}
	else
		*stack_a = NULL;
	first_b = first_a;
	first_b->prev = NULL;
	first_b->next = *stack_b;
	*stack_b = first_b;
//	first_b->next = (*stack_b)->next;//repetition ?
//	if ((*stack_b)->next)
//	{
//	write(1, "Entered if\n", 8);
		tmp = (*stack_b)->next;
		while (tmp != NULL)
		{
			tmp->index++;
			tmp = tmp->next;
		}
//	}
}*/
