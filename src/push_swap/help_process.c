/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:34:30 by ks19              #+#    #+#             */
/*   Updated: 2024/05/18 13:52:50 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atoi2(const char *str, t_var *var)
{
	var->nb = 0;
	var->mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			var->mod *= -1;
		str++;
	}
	if (!*str)
		return (2147483648);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			ft_error();
		var->nb = var->nb * 10 + (*str - 48);
		str++;
	}
	if ((var->mod * var->nb) > 2147483647 || (var->mod * var->nb) < -2147483648)
		ft_error();
	return (var->mod * var->nb);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lastnode(*stack))->next = stack_new;
}

t_stack	*ft_lastnode(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}

int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
