/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lst_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 14:58:39 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_combi_clear(t_list **tmp, t_list **dupli_a)
{
	ft_lstclear(tmp, free);
	ft_lstclear(dupli_a, free);
}

int	is_array_sorted(t_stacks *s)
{
	int	i;

	if (s->a_size < 2)
	{
		if (s->a[0] < s->a[1])
			return (1);
		return (0);
	}
	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	init_stacks(t_list **stack_a, t_stacks *s)
{
	s->a_size = ft_lstsize(*stack_a);
	s->b_size = 0;
	s->a = malloc(s->a_size * sizeof(int));
	if (s->a == NULL)
	{
		free(s);
		return ;
	}
	s->b = malloc(s->a_size * sizeof(int));
	if (s->b == NULL)
	{
		free(s->a);
		free(s);
		return ;
	}
}

t_stacks	*complete_stacks(t_list **stack_a, t_stacks *s)
{
	int		i;
	t_list	*duplicate;
	t_list	*dup;

	duplicate = ft_lstduplicate(*stack_a);
	dup = duplicate;
	i = 0;
	while (duplicate != NULL)
	{
		s->a[i] = duplicate->content;
		i++;
		duplicate = duplicate->next;
	}
	if (dup)
		ft_lstclear(&dup, free);
	return (s);
}

int	create_index(t_stacks *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->a_size * sizeof(int));
	if (new_a == NULL)
		return (-1);
	i = 0;
	while (i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
		i++;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
	return (0);
}
