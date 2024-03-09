#include "push_swap.h"


int	is_array_sorted(t_list *s)
{
	int	i;

	i = 0;
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	create_index(t_stacks *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->a_size * sizeof * new_a);
	if (new_a == NULL)
	//	free_and_exit_with_message(s, "Error\n");
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
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
	j = -1;
	while (++j <= bit_size)
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
	}
	while (s->b_size != 0)
		pa_push_radix(s);
}

void    rb_rotate_radix(int *tab, int size)
{
    int tmp;

    if (size < 0)
        return ;
    tmp = tab[0];
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	tab[size - 1] = tmp;
	write(1, "rb", 2);
}
void    ra_rotate_radix(int *tab, int size)
{
    int tmp;

    if (size < 0)
        return ;
    tmp = tab[0];
	ft_memmove(tab, tab + 1, sizeof(int) * (size - 1));
	tab[size - 1] = tmp;
	write(1, "ra", 2);
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
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
		s->a_size++;
    write(1, "pa", 2);
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
	ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
	s->b_size++;
     write(1, "pb", 2);
}

