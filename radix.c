/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:34:10 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 15:01:50 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rb_rotate_radix(s->b, s->b_size);
		else
			pa_push_radix(s);
	}
	if (is_array_sorted(s))
		while (s->b_size != 0)
			pa_push_radix(s);
}

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = 0;
	while (j <= bit_size)
	{
		size = s->a_size;
		while (size-- && !is_array_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				pb_push_radix(s);
			else
				ra_rotate_radix(s->a, s->a_size);
		}
		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
		j++;
	}
	while (s->b_size != 0)
		pa_push_radix(s);
	free_stacks(s);
}

void	free_stacks(t_stacks *s)
{
	free(s->a);
	free(s->b);
	free(s);
}

void	rb_rotate_radix(int *tab, int size)
{
	int	tmp;

	if (size < 1)
		return ;
	tmp = tab[0];
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	tab[size - 1] = tmp;
	ft_printf("rb\n");
}
