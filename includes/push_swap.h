/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <ksainte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:33:36 by ksainte           #+#    #+#             */
/*   Updated: 2024/05/18 14:14:20 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_var
{
	int				og;
	int				size_b;
	int				size_a;
	int				cost_b;
	int				cost_a;
	int				g;
	int				h;
	int				k;
	int				original_cost;
	int				z;
	int				b;
	int				j;
	int				i;
	int				pos;
	int				mod;
	long long int	nb;
}					t_var;

t_stack				*ft_stack_new(int content);
int					ft_checkdup(t_stack *a);
void				ft_error(void);
void				ft_free(t_stack **lst);
int					ft_checksorted(t_stack *stack_a, t_var *var);
void				ft_freestr(char **lst);
void				ft_add_back(t_stack **stack, t_stack *stack_new);
long				ft_atoi2(const char *str, t_var *var);
void				ft_sort(t_stack **stack_a, t_var *var);
void				ft_sa(t_stack **a, int j);
t_stack				*ft_lastnode(t_stack *lst);
int					ft_listsize(t_stack *lst);
void				ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_sort_three(t_stack **stack_a, t_var *var);
int					ft_min(t_stack *a);
int					ft_max(t_stack *a);
void				ft_ra(t_stack **a, int j);
void				ft_pa(t_stack **a, t_stack **b, int j);
void				ft_rra(t_stack **a, int j);
void				ft_ss(t_stack **a, t_stack **b, int j);
t_stack				*ft_listlast(t_stack *lst);
void				ft_rb(t_stack **b, int j);
void				ft_sb(t_stack **b, int j);
void				ft_rrb(t_stack **b, int j);
int					ft_min_pos(t_stack *a);
int					ft_max_pos(t_stack *a);
void				ft_rr(t_stack **a, t_stack **b, int j);
void				ft_rrr(t_stack **a, t_stack **b, int j);
void				ft_sortsorted(t_stack **stack_a, t_var *var);
int					ft_calculate_cost(t_stack *stack_a, t_stack *stack_b,
						t_var *var);
void				ft_lower_and_or_lower(t_var *var);
void				ft_lower_and_higher(t_var *var);
void				ft_higher_and_higher(t_var *var);
void				ft_higher_and_lower(t_var *var);
void				ft_new_least_exp_element(t_var *var);
int					ft_calculate_b(t_stack *stack_a, t_stack *stack_b,
						t_var *var);
void				ft_initialize_main(t_stack *stack_a, t_stack *stack_b,
						t_var *var);
void				ft_rr_and_ra(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
void				ft_rr_and_rb(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
void				ft_ra_or_rb(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
void				ft_ra_and_rrb(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
void				ft_rotate_a(t_stack **stack_a, t_var *var);
void				ft_rrr_and_rra(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
void				ft_rrr_and_rrb(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
void				ft_rra_and_rb(t_stack **stack_a, t_stack **stack_b,
						t_var *var);
int					ft_calculate_cost_to_a(t_stack *stack_a, t_stack *stack_b,
						t_var *var);

#endif