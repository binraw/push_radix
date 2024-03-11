/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:34:10 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 11:34:11 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
    s->b_size =  0;
    s->a = malloc(s->a_size  *sizeof(int));
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
t_stacks   *complete_stacks(t_list **stack_a, t_stacks *s)
{
    int  i;
    t_list  *duplicate;
    t_list  *dup;

    duplicate = ft_lstduplicate(*stack_a);
    dup = duplicate;
    i = 0;
    while (duplicate != NULL)
    {
        s->a[i] = duplicate->content;
        i++;
        duplicate = duplicate->next;
        
    }
    ft_lstclear(&dup, free);
    return (s);
}

void	create_index(t_stacks *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->a_size * sizeof(int));
	if (new_a == NULL)
	{
        free(s);
        write(1, "Error\n", 6);
        return ;
    }
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
}

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

void    rb_rotate_radix(int *tab, int size)
{
    int tmp;

    if (size < 1)
        return ;
    
    tmp = tab[0];
    
   
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	 tab[size - 1] = tmp;
	ft_printf("rb\n");
}
void    ra_rotate_radix(int *tab, int size)
{
    int tmp;

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

void    pb_push_radix(t_stacks *s)
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
