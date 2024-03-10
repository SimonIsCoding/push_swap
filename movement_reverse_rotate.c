/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:53 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/05 16:29:15 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	the_reverse_rotate(t_list **lst)
{
    if (*lst == NULL || (*lst)->next == NULL) {
        // Rien à faire s'il n'y a pas de nœuds ou s'il n'y a qu'un seul nœud dans la liste
        return;
    }

    t_list *last = *lst;
    t_list *second_last = NULL;

    // Parcours de la liste jusqu'au dernier nœud et mémorisation du deuxième dernier nœud
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    // Ajustement des pointeurs pour échanger le premier et le dernier nœud
    last->next = (*lst)->next; // Le next du dernier devient le second nœud
    (*lst)->next->prev = last; // Le previous du second nœud devient le dernier
    last->prev = NULL; // Le previous du dernier devient NULL
    last->next = *lst; // Le next du dernier devient le premier
    (*lst)->prev = last; // Le previous du premier devient le dernier
    *lst = last; // Mettre à jour la tête de liste avec le dernier nœud
	second_last->next = NULL;
	increment_index(*lst);
	last->index = 0;
}

//the last element becomes the first one
void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*first;
	t_list	*second_to_last;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		write(1, "useless movement rr\n", 20);//TO REMOVE BEFORE PUSHING
		return ;
	}
	last = ft_lstlast(*lst);
	first = *lst;
	second_to_last = last->prev;

	first->prev = last;
	last->next = first;
	last->prev = NULL;
	second_to_last->next = NULL;
	*lst = last;
	increment_index(*lst);
	last->index = 0;
}

void	reverse_rotate_a(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		write(1, "useless movement rra\n", 21);//TO REMOVE BEFORE PUSHING
		return ;
	}
	the_reverse_rotate(stack_a);
	if (write(1, "rra\n", 4) == -1)
		exit(1);
}

void	reverse_rotate_b(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement rrb\n", 21);//TO REMOVE BEFORE PUSHING
		return ;
	}
	the_reverse_rotate(stack_b);
	if(write(1, "rrb\n", 4) == -1)
		exit(1);
}

//the last element becomes the first one for both stacks
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
	{
		write(1, "useless movement rrr\n", 21);//TO REMOVE BEFORE PUSHING
		return ;
	}
	the_reverse_rotate(stack_a);
	the_reverse_rotate(stack_b);
	if (write(1, "rrr\n", 4) == -1)
		exit(1);
}
