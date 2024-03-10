/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:39:30 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/09 16:51:47 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//we want the llast at the top
/*void	the_reverse_rotate(t_list *stack_a)
{
//	t_list	*tmp;
	t_list	*first;
	t_list	*last;
	t_list	*second_to_last;
	
	first = stack_a;
	while (stack_a->next->next != NULL)
		stack_a = stack_a->next;
	second_to_last = stack_a;
	last = stack_a->next;
	second_to_last->next = NULL;
	last->next = first;
}*/

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
}
