/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:06:35 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/11 15:06:34 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_list **stack_a, char *value)
{
	char	**str;
	int		i;
	long	n;

	i = 0;
	if (!value)
		return (0);
	str = ft_split(value, ' ');
	while (str[i])
	{
		n = ft_atoi(str[i]);
		ft_lstadd_back(stack_a, ft_lstnew(n));
		if (ft_lstnew(n) == NULL)
			return (-1);
		i++;
	}
	free(str[0]);
	free(str);
	return (0);
}

int	build_stack(int argc, char **argv, t_list **stack_a)
{
	int		i;
	long	n;
	int		y;

	i = 0;
	n = 0;
	y = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (error_free_stack(stack_a), -1);
		if (ft_strlen(argv[i]) > 1 && i == 1)
		{
			y = stack_init(stack_a, argv[i]);
			if (y == -1)
				return (-1);
		}
		else
		{
			if (ft_lstadd_back(stack_a, ft_lstnew((int)n)) == -1)
				return (-1);
		}
	}
	return (0);
}

void	control_sort_list(t_list **stack_a, t_list **stack_b)
{
	t_stacks	*s;

	s = malloc(sizeof(t_stacks));
	if (!s)
	{
		ft_lstclear(stack_a, free);
		return ;
	}
	s->a_size = 0;
	if (ft_lstsize(*stack_a) == 2)
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa_swap(stack_a);
	if (ft_lstsize(*stack_a) == 3)
		sort_three_numbers(three_digit(*stack_a), stack_a);
	if (ft_lstsize(*stack_a) == 5 || ft_lstsize(*stack_a) == 4)
		five_digit(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 5)
		big_algo(stack_a, s);
	if (ft_lstsize(*stack_a) <= 5 && create_index(s) == 0)
		free(s);
	if (stack_b)
		ft_combi_clear(stack_a, stack_b);
	else
		ft_lstclear(stack_a, free);
}

void	big_algo(t_list **stack_a, t_stacks *s)
{
	init_stacks(stack_a, s);
	s = complete_stacks(stack_a, s);
	if (create_index(s) == -1)
	{
		free_stacks(s);
		return ;
	}
	radix_sort(s);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!argc)
		return (-1);
	if (argc < 2)
		return (-1);
	if (alpha_check(argv) == -1)
		return (-1);
	if (build_stack(argc, argv, &stack_a) == -1)
		return (-1);
	if (error_value(&stack_a, &stack_b) == -1)
		return (-1);
	control_sort_list(&stack_a, &stack_b);
}
