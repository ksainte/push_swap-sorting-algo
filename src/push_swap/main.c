/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:37:17 by ks19              #+#    #+#             */
/*   Updated: 2024/05/23 16:11:26 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_stack	*ft_sub_process(char **argv, t_var *var)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	long	j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i], var);
		if (j == 2147483648)
			ft_error();
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv, t_var *var)
{
	t_stack	*a;
	int		i;
	long	j;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = ft_sub_process(argv, var);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i], var);
			if (j == 2147483648)
				ft_error();
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_var	var;

	if (argc == 1)
		return (0);
	if (argc == 2 && *argv[1] == '\0')
		return (0);
	a = NULL;
	a = ft_process(argc, argv, &var);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (ft_checksorted(a, &var))
		ft_sortsorted(&a, &var);
	else
		ft_sort(&a, &var);
if (a)
    {
     printf("This is the stack a after:\n");
     t_stack *current = a;
     while (current){
             printf("%ld\n", current->nbr);
             current = current->next;
     }
    }
//     int i = 0;
//     if (a)
//     {
//      printf("Checking if everyting is in ascending order...\n");
//      t_stack *current1 = a;
//      while (current1!= NULL && current1->next->nbr > current1->nbr)
//      {
//          i++;
//              current1 = current1->next;
//              if (current1->next == NULL){
//                  break ;
//              }
//      }
//      printf("Everything is ok if i is %d!\n", i);
//     }

	ft_free(&a);
	return (0);
}
