/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:03:45 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 14:59:32 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_push(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb_push(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*next_to;

	head = *stack;
	tail = ft_lstlast(head);
	next_to = tail->prev;
	tail->next = head;
	*stack = head->next;
	head->next = NULL;
	tail->prev = next_to;
	head->prev = tail;
}

void	ra_rotate(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb_rotate(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
