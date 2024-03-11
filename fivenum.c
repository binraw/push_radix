/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:51:53 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 15:05:08 by rtruvelo         ###   ########.fr       */
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

void	ra_rotate_radix(int *tab, int size)
{
	int	tmp;

	if (size < 1)
		return ;
	tmp = tab[0];
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	tab[size - 1] = tmp;
	ft_printf("ra\n");
}

void	pa_push_radix(t_stacks *s)
{
	int	tmp;

	if (s->b_size <= 0)
		return ;
	tmp = s->b[0];
	ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
	s->a[0] = tmp;
	s->b_size--;
	s->a_size++;
	ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
	ft_printf("pa\n");
}

void	pb_push_radix(t_stacks *s)
{
	int	tmp;

	if (s->a_size <= 0)
		return ;
	tmp = s->a[0];
	ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
	s->b[0] = tmp;
	s->a_size--;
	s->b_size++;
	ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
	ft_printf("pb\n");
}
