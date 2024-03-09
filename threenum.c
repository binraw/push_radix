/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threenum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:30:40 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 14:10:59 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_digit(t_list *stack_a)
{
	t_list	*lst;

	lst = stack_a;
	if (lst->content > lst->next->content && lst->content
		< lst->next->next->content && lst->next->content
		< lst->next->next->content)
		return (1);
	else if (lst->content > lst->next->content && lst->content
		> lst->next->next->content && lst->next->content
		> lst->next->next->content)
		return (2);
	else if (lst->content > lst->next->content && lst->content
		> lst->next->next->content)
		return (3);
	else if (lst->content < lst->next->content && lst->content
		< lst->next->next->content && lst->next->content
		> lst->next->next->content)
		return (4);
	else if (lst->content < lst->next->content && lst->content
		> lst->next->next->content)
		return (5);
	return (0);
}

int	sort_three_numbers(int num, t_list **stack_a)
{
	if (num == 0)
		return (-1);
	else if (num == 1)
		sa_swap(stack_a);
	else if (num == 2)
		sa_rra(stack_a);
	else if (num == 3)
		ra_rotate(stack_a);
	else if (num == 4)
		rra_sa(stack_a);
	else if (num == 5)
		rra_rotate(stack_a);
	return (0);
}

void	rra_sa(t_list **stack_a)
{
	rra_rotate(stack_a);
	sa_swap(stack_a);
}

void	sa_rra(t_list **stack_a)
{
	sa_swap(stack_a);
	rra_rotate(stack_a);
}

void	sort_two_elemb(t_list *stack_b)
{
	if (stack_b->content > stack_b->next->content)
		sb_swap(&stack_b);
}
