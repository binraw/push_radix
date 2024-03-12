/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:49 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/12 10:58:22 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "printf/libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				second_part;
	int				size;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

t_stacks	*complete_stacks(t_list **stack_a, t_stacks *s);
t_list		*ft_lstnew(int content);
int			ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			is_empty_t_list(t_list *li);
void		print_liste(t_list *liste);
int			ft_lstcontains(t_list *list, int value);
int			ft_lstsize(t_list *head);
t_list		*ft_lstlast2(t_list *lst);
int			rrr_rotate(t_list **stack_a, t_list **stack_b);
void		rrb_rotate(t_list **stack_b);
void		rra_rotate(t_list **stack_a);
void		reverse_rotate(t_list **stack);
void		rr_rotate(t_list **stack_a, t_list **stack_b);
void		rb_rotate(t_list **stack_b);
void		ra_rotate(t_list **stack_a);
void		rotate(t_list **stack);
void		pb_push(t_list **stack_a, t_list **stack_b);
void		pa_push(t_list **stack_a, t_list **stack_b);
void		push(t_list **stack_to, t_list **stack_from);
int			ss_swap(t_list **stack_a, t_list **stack_b);
void		sb_swap(t_list **stack_b);
void		sa_swap(t_list **stack_a);
void		swap(t_list **stack);
void		sort_two_elemb(t_list *stack_b);
int			check_is_biggest(t_list *lst, t_list *lst_b);
int			check_is_minimal(t_list *lst, t_list *lst_b);
int			biggest_finder(t_list *lst);
int			minimal_finder(t_list *lst);
int			check_is_rra(t_list *lst);
t_list		*ft_lstduplicate(const t_list *original);
int			five_digit(t_list **stack_a, t_list **stack_b);
int			three_digit(t_list *stack_a);
int			sort_three_numbers(int num, t_list **stack_a);
void		sa_rra(t_list **stack_a);
void		rra_sa(t_list **stack_a);
int			check_dup(t_list *stack_a);
int			write_error(int result);
int			alpha_check(char **argv);
int			ft_isalpha(int c);
int			control_order(t_list **stack_a);
int			check_sorted(int nb);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_combi_clear(t_list **tmp, t_list **dupli_a);
int			build_stack(int argc, char **argv, t_list **stack_a);
int			error_value(t_list **stack_a, t_list **stack_b);
void		control_sort_list(t_list **stack_a, t_list **stack_b);
int			condition_papush(t_list **tmp, t_list **dupli_a);
int			stack_init(t_list **stack_a, char *value);
void		pb_push_radix(t_stacks *s);
void		pa_push_radix(t_stacks *s);
void		ra_rotate_radix(int *tab, int size);
void		rb_rotate_radix(int *tab, int size);
void		radix_sort(t_stacks *s);
void		radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j);
int			create_index(t_stacks *s);
int			is_array_sorted(t_stacks *s);
int			init_stacks(t_list **stack_a, t_stacks *s);
void		free_stacks(t_stacks *s);
int		big_algo(t_list **stack_a, t_stacks *s);
void		error_free_stack(t_list **stack_a);

#endif