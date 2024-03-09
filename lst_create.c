/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:44 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 13:24:12 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_t_list(t_list *li)
{
	if (li == NULL)
		return (1);
	return (0);
}

t_list	*ft_lstduplicate(const t_list *original)
{
	t_list	*copy;
	t_list	*original_ptr;
	t_list	*copy_ptr;

	copy = ft_lstnew(original->content);
	if (!copy)
		return (NULL);
	original_ptr = original->next;
	copy_ptr = copy;
	if (!original)
		return (NULL);
	while (original_ptr)
	{
		copy_ptr->next = ft_lstnew(original_ptr->content);
		if (!copy_ptr->next)
		{
			ft_lstclear(&copy, free);
			return (NULL);
		}
		copy_ptr = copy_ptr->next;
		original_ptr = original_ptr->next;
	}
	return (copy);
}

void	print_liste(t_list *liste)
{
	t_list	*current;

	if (liste == NULL)
	{
		ft_printf("NULL\n");
	}
	current = liste;
	while (current != NULL)
	{
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("NULL\n");
}

int	ft_lstcontains(t_list *list, int value)
{
	while (list != NULL)
	{
		if (list->content == value)
			return (1);
		list = list->next;
	}
	return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
