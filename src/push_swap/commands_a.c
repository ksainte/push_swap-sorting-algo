/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:09:21 by ks19              #+#    #+#             */
/*   Updated: 2024/05/23 16:05:22 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//all commands need to receipt a double pointer 
//because they will make changes to
//the received stacks

void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

// ra (rotate a) : shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_listlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

//imaginons une stack 3 1 2 4
//*a  = last : *a devient alors &4
//(*a)->next fait de *a une liste circulaire. &4 pointe desormais sur &3 tell que 3 1 2 4->
//*a = tmp->next fait de *a une liste tell que 1 2 4 3-> (->meaning tjrs circulaire)
//tmp->next = NULL coupe la liste circulaire, &3 pointe desormais sur NULL, on a desormais 1 2 4 3

// pa (push a) : take the first element at the top of b and
// put it at the top of a. Do nothing if b is empty.
void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1.
// The last element becomes the first one.
void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}
