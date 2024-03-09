/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:10:06 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 12:44:14 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_minimal(t_list **stack_a, t_list **stack_b)
{
	orga_lst(stack_a);
	pa_push(stack_a, stack_b);
	ra_rotate(stack_a);
}

void	orga_papush(t_list **stack_a, t_list **stack_b)
{
	orga_lst(stack_a);
	pa_push(stack_a, stack_b);
}

void	papush_sa(t_list **stack_a, t_list **stack_b)
{
	pa_push(stack_a, stack_b);
	sa_swap(stack_a);
}

int	orga_lst(t_list **stack_a)
{
	if (ft_find_index(*stack_a, minimal_finder(*stack_a))
		>= count_mediane(*stack_a))
	{
		while ((*stack_a)->content != minimal_finder(*stack_a))
			rra_rotate(stack_a);
	}
	else
	{
		while ((*stack_a)->content != minimal_finder(*stack_a))
			ra_rotate(stack_a);
	}
	return (0);
}

int	orga_lst_order(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*dupli_a;

	tmp = ft_lstduplicate(*stack_b);
	dupli_a = ft_lstduplicate(*stack_a);
	while ((*stack_a)->content != minimal_finder(*stack_a))
	{
		if (tmp->content < ft_lstlast(*stack_a)->content
			&& tmp->content > minimal_finder(*stack_a))
		{
			break ;
		}
		ra_rotate(stack_a);
	}
	ft_lstclear(&tmp, free);
	ft_lstclear(&dupli_a, free);
	return (0);
}