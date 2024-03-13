/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:54:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 14:59:11 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_finder(t_list *lst)
{
	int	biggest;

	if (!lst)
		return (0);
	biggest = lst->content;
	while (lst != NULL)
	{
		if (biggest <= lst->content)
			biggest = lst->content;
		lst = lst->next;
	}
	return (biggest);
}

int	minimal_finder(t_list *lst)
{
	int	minimal;

	minimal = lst->content;
	while (lst != NULL)
	{
		if (minimal >= lst->content)
			minimal = lst->content;
		lst = lst->next;
	}
	return (minimal);
}

int	minimal_index(t_list *lst)
{
	int	minimal;
	int	i;
	int	min_index;

	minimal = lst->content;
	i = 0;
	min_index = 0;
	if (lst == NULL)
		return (-1);
	while (lst != NULL)
	{
		if (minimal >= lst->content)
		{
			minimal = lst->content;
			min_index = i;
		}
		i++;
		lst = lst->next;
	}
	return (min_index);
}

int	control_order(t_list **stack_a)
{
	t_list	*temp;
	t_list	*dup;

	dup = ft_lstduplicate(*stack_a);
	if (!dup)
		return (-1);
	temp = dup;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
		{
			ft_lstclear(&dup, free);
			return (-1);
		}
		temp = temp->next;
	}
	ft_lstclear(&dup, free);
	return (0);
}

void	error_free_stack(t_list **stack_a)
{
	write_error(-1);
	ft_lstclear(stack_a, free);
}
