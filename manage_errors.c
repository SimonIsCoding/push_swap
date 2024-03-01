/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:02:32 by simarcha          #+#    #+#             */
/*   Updated: 2024/03/01 17:36:26 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//create functions to handle error
//this means that:
//1) if this is not a number <=> != from 48 to 57

//2) if there is two same numbers

//3) if there is no arguments => finish directly the pgrm

/*4) with this "" => you have to manage the fact that every nodes are separated with a space
 * there should not have any more arguments*/

//5) if the number are already sorted => finish directly the pgrm

//6) you have to manage the fact when there is several spaces => only with the argument with ""

int	write_error(void)
{
	return (write(1, "Error\n", 6));
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

//1) we want to create a function to check if it's not a number
//then we will use a function that check if every char of this argument are numbers
void	is_a_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0') 
		{
			if (ft_isdigit((int)argv[i][j]) == 0)
			{
				return (write_error(), exit(1));
			}
			j++;
		}
		i++;
	}
}

//we have to return an error if we have two same numbers
void	two_same_numbers(t_list *lst)
{
	t_list	*tmp;
	int		check;

	check = 0;
	while (lst != NULL)
	{
		tmp = lst;
		check = 0;
		while (tmp != NULL)
		{
			if (tmp->nb == lst->nb)
				check++;
			tmp = tmp->next;
		}
		if (check > 1)	
			return (ft_lstclear(&lst), lst = NULL, write_error(), exit(1));
		lst = lst->next;
	}
}

//This functions checks if the number are already sorted. 
//If yes, we go out successfully
int	sorted_check(t_list	*lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->next->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

//we need to handle the case when there is "" put as an arg
//if argc == 2 && argv[1][i] contains spaces
//	->it doesn't have to contains multiples spaces
//	->it has to  be well written

//we have to verify the case when we have two followed spaces
//we have to verify the case when it's not a number
//we have to verify the case when there is two same numbers
//then we have to create the list if everything is okay => we might create another function for it=>It depends

t_list	*create_list_argc_is_2(char **argv)
{
	char	**array;
	t_list	*lst;
	int		i;
	int		nb;
	t_list	*new_node;

	i = 0;
	lst = NULL;
	array = ft_split(argv[1], ' ');
	while (array[i])
	{
		nb = ft_atol(array[i]);
		new_node = ft_lstnew(nb, i);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

void	argc_is_2(char **argv)
{
	int		i;
	t_list	*lst;

	i = 0;
	while (argv[1][i] != '\0' && (size_t)i < ft_strlen(*argv) - 1)
	{
		if ((argv[1][i] == 32 && argv[1][i + 1] == 32)
				|| (argv[1][ft_strlen(argv[1]) - 1] == 32 || argv[1][0] == 32))
			return (write(1, "1st\n", 4), write_error(), exit(1));
		if (!(ft_isdigit((int)argv[1][i]) == 1 || (argv[1][i] == ' ')))
			return (write(1, "2nd\n", 4), write_error(), exit(1));
		i++;
	}
	lst = create_list_argc_is_2(argv);
	if (!lst)
		return (exit(1));
	two_same_numbers(lst);
	sorted_check(lst);
	if (sorted_check(lst) == 1)
	{
		printf("numbers are sorted\n");
		exit(0);
	}
	printf("numbers not sorted => we can sort them\n");
	printf("Well written\n");
}
//how to create a list from the argv[1]
//on veut compter les nombres de caracteres qu'il y a 
//la taille de notre liste sera du nb d'espaces + 1
//Comment creer un noeud lorsque notre numero contient plusieurs chiffres
//on creer une string a chaque caractere apres un espace
//	=>tant que ce n'est pas un espace, on ajoute le digit a notre string
//	=> si c'est un espace, on ajoute le noeud a notre liste

//utilises le split pour couper les numeros
//le split te donnera une array
//chaque array[i] sera ton noeud



void	manage_error(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 2)
	{
		argc_is_2(argv);
		return ;
	}
	is_a_number(argc, argv);
	stack_a = create_list(argc, argv);
	two_same_numbers(stack_a);
	sorted_check(stack_a);
	if (sorted_check(stack_a) == 1)
	{
		write(1, "numbers are sorted\n", 19);
		exit(0);
	}
	printf("numbers not sorted => we can sort them\n");
	printf("Well written\n");
}
