/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:14:24 by ks19              #+#    #+#             */
/*   Updated: 2024/05/17 18:23:55 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}
