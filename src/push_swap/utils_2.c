/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:40:29 by ks19              #+#    #+#             */
/*   Updated: 2024/05/17 20:52:23 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_listsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_sortsorted(t_stack **stack_a, t_var *var)
{
	var->pos = ft_min_pos(*stack_a);
	var->size_a = ft_listsize(*stack_a);
	if (var->pos <= var->size_a / 2)
	{
		while (var->pos > 0)
		{
			ft_ra(stack_a, 0);
			var->pos--;
		}
	}
	else
	{
		var->g = var->size_a - var->pos;
		while (var->g > 0)
		{
			ft_rra(stack_a, 0);
			var->g--;
		}
	}
}

int	ft_checksorted(t_stack *stack_a, t_var *var)
{
	t_stack	*tmp;

	var->pos = ft_min_pos(stack_a);
	var->size_a = ft_listsize(stack_a);
	tmp = ft_lastnode(stack_a);
	tmp->next = stack_a;
	while (var->pos > 0)
	{
		stack_a = stack_a->next;
		var->pos--;
	}
	var->i = stack_a->nbr;
	while (var->size_a > 0)
	{
		if (var->i > stack_a->nbr)
		{
			tmp->next = NULL;
			return (0);
		}
		var->i = stack_a->nbr;
		stack_a = stack_a->next;
		var->size_a--;
	}
	tmp->next = NULL;
	return (1);
}
