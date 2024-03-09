/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:51:53 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/06 14:12:00 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	five_digit(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->content != minimal_finder(*stack_a))
		ra_rotate(stack_a);
	pb_push(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 3)
	{
		while ((*stack_a)->content != biggest_finder(*stack_a))
			ra_rotate(stack_a);
		pb_push(stack_a, stack_b);
	}
	sort_three_numbers(three_digit(*stack_a), stack_a);
	pa_push(stack_a, stack_b);
	if (ft_lstsize(*stack_b) != 0)
	{
		ra_rotate(stack_a);
		pa_push(stack_a, stack_b);
	}
	return (0);
}

int	rr_transfer_combi(t_list **stack_a, t_list **stack_b, int index)
{
	int	count;
	int	x;

	x = index;
	count = count_number_rota(stack_b, (*stack_a)->content);
	if (index < count)
		index = rr_transfer(stack_a, stack_b, index);
	count = count - (x - index);
	x = index;
	if (count < index)
		index = rr_transfer_count(stack_a, stack_b, index);
	count = count - (x - index);
	return (count);
}

void	transfer_num_ra(t_list **stack_a, t_list **stack_b, int index)
{
	int		count;
	t_list	*stack_from;

	index = 0;

	stack_from = ft_lstduplicate(*stack_b);
	count = count_number_rota(stack_b, (*stack_a)->content);
	if(index > count)
	{
	// 	while (count > 0 && index >0)
	// 	{
	// 		rr_rotate(stack_a, stack_b);
	// 		index--;
	// 	}
	}
			
	// if (index != count)
    // {
    // while (count > 0 && index >0)
	// {
	// 	rr_rotate(stack_a, stack_b);
	// 	count--;
	// 	index--;
	// }
	// }
	// index = ra_transfer(stack_a, index);
	else if (count <= count_mediane(*stack_b))
		count = rb_transfer(stack_b, count);
	else
		count = rrb_transfer(stack_b, count);
	pb_push(stack_a, stack_b);
	ft_lstclear(&stack_from, free);
}

int	condition_find(int nbr_push, t_list **stack_from)
{
	if (nbr_push > biggest_finder(*stack_from)
		|| nbr_push < minimal_finder(*stack_from))
		return (1);
	return (0);
}
