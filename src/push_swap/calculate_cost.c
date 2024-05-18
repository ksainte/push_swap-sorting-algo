/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:56:13 by ks19              #+#    #+#             */
/*   Updated: 2024/05/18 16:36:22 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_best_fit_in_b(t_stack *head_a, t_stack *head_b, t_var *var)
{
	while (head_b->next != NULL)
	{
		if (var->i < head_b->next->nbr
			&& head_b->next->nbr < head_a->nbr)
		{
			var->i = head_b->next->nbr;
			head_b = head_b->next;
			var->j++;
			var->k = var->j;
		}
		else
		{
			head_b = head_b->next;
			var->j++;
		}
	}
}

void	ft_skip_head(t_stack **head, t_var *var)
{
	var->i = (*head)->next->nbr;
	*head = (*head)->next;
	var->j++;
	var->k = var->j;
}

int	ft_calculate_cost(t_stack *stack_a, t_stack *stack_b, t_var *var)
{
	if ((stack_a)->nbr < ft_min(stack_b))
	{
		var->pos = ft_max_pos(stack_b);
		return (var->pos);
	}
	var->j = 0;
	var->k = 0;
	var->i = stack_b->nbr;
	while (stack_b != NULL && stack_a->nbr < var->i)
		ft_skip_head(&stack_b, var);
	ft_best_fit_in_b(stack_a, stack_b, var);
	return (var->k);
}

void	ft_best_fit_in_a(t_stack *head_a, t_stack *head_b, t_var *var)
{
	while (head_a->next != NULL)
	{
		if (var->i > head_a->next->nbr
			&& head_a->next->nbr > head_b->nbr)
		{
			var->i = head_a->next->nbr;
			head_a = head_a->next;
			var->j++;
			var->k = var->j;
		}
		else
		{
			head_a = head_a->next;
			var->j++;
		}
	}
}

int	ft_calculate_cost_to_a(t_stack *stack_a, t_stack *stack_b, t_var *var)
{
	if ((stack_b)->nbr > ft_max(stack_a))
	{
		var->pos = ft_min_pos(stack_a);
		return (var->pos);
	}
	var->j = 0;
	var->k = 0;
	var->i = stack_a->nbr;
	while (stack_a != NULL && stack_b->nbr > var->i)
		ft_skip_head(&stack_a, var);
	ft_best_fit_in_a(stack_a, stack_b, var);
	return (var->k);
}
