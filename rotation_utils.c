/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:03:45 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/06 15:48:12 by rtruvelo         ###   ########.fr       */
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

// void	ra_rotate_void(t_list **stack_a)
// {
// 	rotate(stack_a);
	
// }

void	rb_rotate(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

int	rr_transfer(t_list **stack_a, t_list **stack_b, int index)
{
	int	count;

	count = count_number_rota(stack_b, (*stack_a)->content);
	while (index >= 0)
	{
		rr_rotate(stack_a, stack_b);
		index--;
		count--;
	}
	return (index);
}

int	rr_transfer_count(t_list **stack_a, t_list **stack_b, int index)
{
	int	count;

	count = count_number_rota(stack_b, (*stack_a)->content);
	while (count > 0)
	{
		rr_rotate(stack_a, stack_b);
		index--;
		count--;
	}
	return (index);
}

int	ra_transfer(t_list **stack_a, int index)
{
	while (index > 0)
	{
		ra_rotate(stack_a);
		index--;
	}
	return (index);
}

int	rb_transfer(t_list **stack_b, int count)
{
	while (count > 0)
	{
		rb_rotate(stack_b);
		count--;
	}
	return (count);
}

int	rrb_transfer(t_list **stack_b, int count)
{
	count = ft_lstsize(*stack_b) - count;
	while (count > 0)
	{
		rrb_rotate(stack_b);
		count--;
	}
	return (count);
}