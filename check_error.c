/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:20:39 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/28 12:47:05 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->content == tmp->content)
				return (-1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	free(tmp);
	return (0);
}

int	write_error(int result)
{
	if (result == -1)
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	return (0);
}

int	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]))
			{
				write_error(-1);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sorted(int nb)
{
	if (nb == 1)
		return (1);
	return (0);
}

int	error_value(t_list **stack_a, t_list **stack_b)
{
	if (write_error(check_dup(*stack_a)) == -1)
	{
		ft_combi_clear(stack_a, stack_b);
		return (-1);
	}
	if (control_order(stack_a) == 0)
	{
		ft_combi_clear(stack_a, stack_b);
		return (-1);
	}
	return (0);
}
