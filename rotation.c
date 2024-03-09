/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:21:17 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 14:04:52 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*next_to;

	head = *stack;
	tail = ft_lstlast(head);
	next_to = ft_lstlast2(head);
	next_to->next = NULL;
	tail->next = head;
	tail->prev = NULL;
	head->prev = tail;
	*stack = tail;
}

void	rra_rotate(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb_rotate(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

int	rrr_rotate(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return (0);
}
