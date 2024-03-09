/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:49 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/06 15:46:40 by rtruvelo         ###   ########.fr       */
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
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		is_empty_t_list(t_list *li);
void	print_liste(t_list *liste);
int		ft_lstcontains(t_list *list, int value);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast2(t_list *lst);
int		rrr_rotate(t_list **stack_a, t_list **stack_b);
void	rrb_rotate(t_list **stack_b);
void	rra_rotate(t_list **stack_a);
void	reverse_rotate(t_list **stack);
void	rr_rotate(t_list **stack_a, t_list **stack_b);
void	rb_rotate(t_list **stack_b);
void	ra_rotate(t_list **stack_a);
void	rotate(t_list **stack);
void	pb_push(t_list **stack_a, t_list **stack_b);
void	pa_push(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_to, t_list **stack_from);
int		ss_swap(t_list **stack_a, t_list **stack_b);
void	sb_swap(t_list **stack_b);
void	sa_swap(t_list **stack_a);
void	swap(t_list **stack);
void	sort_two_elemb(t_list *stack_b);
int		check_is_biggest(t_list *lst, t_list *lst_b);
int		check_is_minimal(t_list *lst, t_list *lst_b);
int		count_mediane(t_list *stack_a);
int		biggest_finder(t_list *lst);
int		minimal_finder(t_list *lst);
int		ft_find_index(t_list *a, int nbr);
int		check_is_rra(t_list *lst);
t_list	*ft_lstduplicate(const t_list *original);
int		big_digit(t_list **stack_a, t_list **stack_b);
int		index_to_push(t_list *stack_a, t_list *stack_b);
int		five_digit(t_list **stack_a, t_list **stack_b);
int		three_digit(t_list *stack_a);
int		sort_three_numbers(int num, t_list **stack_a);
void	sa_rra(t_list **stack_a);
void	rra_sa(t_list **stack_a);
int		ft_find_place_b(t_list *stack_b, int nbr_push);
int		ft_find_place_a(t_list *stack_a, int nbr_push);
int		count_number_rota(t_list **stack_b, int nbr);
int		count_number_rota_a(t_list **stack_a, int nbr);
int		big_digit_to_a(t_list **stack_a, t_list **stack_b);
int		orga_lst(t_list **stack_a);
int		check_dup(t_list *stack_a);
int		write_error(int result);
int		alpha_check(char **argv);
int		ft_isalpha(int c);
int		control_order(t_list **stack_a);
int		check_sorted(int nb);
int		orga_lst_order(t_list **stack_a, t_list **stack_b);
void	push_minimal(t_list **stack_a, t_list **stack_b);
void	orga_papush(t_list **stack_a, t_list **stack_b);
void	papush_sa(t_list **stack_a, t_list **stack_b);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_combi_clear(t_list **tmp, t_list **dupli_a);
int		rr_transfer_combi(t_list **stack_a, t_list **stack_b, int index);
int		rrb_transfer(t_list **stack_b, int count);
int		rb_transfer( t_list **stack_b, int count);
int		ra_transfer(t_list **stack_a, int index);
int		rr_transfer_count(t_list **stack_a, t_list **stack_b, int index);
int		rr_transfer(t_list **stack_a, t_list **stack_b, int index);
int		build_stack(int argc, char **argv, t_list **stack_a);
int		error_value(t_list **stack_a, t_list **stack_b);
void	control_sort_list(t_list **stack_a, t_list **stack_b);
void	transfer_num_ra(t_list **stack_a, t_list **stack_b, int index);
int		condition_papush(t_list **tmp, t_list **dupli_a);
int		condition_find(int nbr_push, t_list **stack_from);
void	stack_init(t_list **stack_a, char *value);
void	ra_rotate_void(t_list **stack_a);


#endif