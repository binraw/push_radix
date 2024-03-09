/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:12:33 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 12:51:28 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_mediane(t_list *stack_a)
{
	int	i;

	i = 0;
	i = ft_lstsize(stack_a);
	i = i / 2;
	return (i);
}

int	count_number_rota(t_list **stack_b, int nbr)
{
	t_list	*stack_from;
	int		i;

	stack_from = ft_lstduplicate(*stack_b);
	i = 0;
	i = ft_find_place_b(stack_from, nbr);
	ft_lstclear(&stack_from, free);
	return (i);
}

int	count_number_rota_a(t_list **stack_a, int nbr)
{
	t_list	*stack_from;
	int		i;

	stack_from = ft_lstduplicate(*stack_a);
	i = 0;
	i = ft_find_place_a(stack_from, nbr);
	ft_lstclear(&stack_from, free);
	return (i);
}
