/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:32:24 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 12:49:32 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_biggest(t_list *lst, t_list *lst_b)
{
	int	biggest;

	biggest = lst->content;
	while (lst_b != NULL)
	{
		if (biggest <= lst_b->content)
			return (0);
		lst_b = lst_b->next;
	}
	return (1);
}

int	check_is_minimal(t_list *lst, t_list *lst_b)
{
	int	minimal;

	minimal = lst->content;
	while (lst_b != NULL)
	{
		if (minimal <= lst_b->content)
			return (0);
		lst_b = lst_b->next;
	}
	return (1);
}

int	check_is_rra(t_list *lst)
{
	if (lst->second_part == 0)
		return (0);
	return (1);
}

int	condition_papush(t_list **tmp, t_list **dupli_a)
{
	if ((*tmp)->content < (*dupli_a)->content
		&& (*tmp)->content > ft_lstlast(*dupli_a)->content)
		return (1);
	return (0);
}
