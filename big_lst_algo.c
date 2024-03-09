/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_lst_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:28:31 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/03/06 15:48:19 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_num_rra(t_list **stack_a, t_list **stack_b, int index)
{
	int		count;
    int pos;
	t_list	*stack_from;

	stack_from = ft_lstduplicate(*stack_b);
	pos = ft_lstsize(*stack_a);
    count = count_number_rota(stack_b, (*stack_a)->content);
    if (index > count_mediane(*stack_a))
    {
        pos = pos - (ft_lstsize(*stack_a) - index + 1);
    
    if (pos < count)
    {
        while (pos > 0)
        {
            rrr_rotate(stack_a, stack_b);
            pos--;
        }
    }
    }
  
    else 
    {
    while (index >= 0)
	{
		rra_rotate(stack_a);
		index--;
	}
	
	while (count > 0)
	{
		rrb_rotate(stack_b);
		count--;
	}
    }

	pb_push(stack_a, stack_b);
	ft_lstclear(&stack_from, free);
}

int	big_digit(t_list **stack_a, t_list **stack_b)
{
	int	y;

	pb_push(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 3)
		pb_push(stack_a, stack_b);
	sort_two_elemb(*stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		y = index_to_push(*stack_a, *stack_b);
		if (y <= count_mediane(*stack_a))
		{
            printf("STACK_A\n");
            print_liste(*stack_a);
            printf("STACK_B\n");
            print_liste(*stack_b);
			transfer_num_ra(stack_a, stack_b, y);
		}
			
		else
	    {
        // printf("STACK_A\n");
        // print_liste(*stack_a);
        // printf("STACK_B\n");
        // print_liste(*stack_b);
		transfer_num_rra(stack_a, stack_b, y);
	    }
			
	}
	sort_three_numbers(three_digit(*stack_a), stack_a);
    //  print_liste(*stack_b);
	while (ft_lstsize(*stack_b) > 0)
	{
		big_digit_to_a(stack_a, stack_b);
	}
		
	orga_lst(stack_a);
    // print_liste(*stack_a);
	return (0);
}

int	index_to_push(t_list *stack_a, t_list *stack_b)
{
	int		i;
	int		x;
	int		count;
    int     pos;
	t_list	*tmp;

	tmp = ft_lstduplicate(stack_a);
	i = 0;
	x = 0;
    pos = ft_lstsize(stack_a);
	count = 0;
	while (i <= ft_lstsize(stack_a))
	{
        if (i > count_mediane(stack_a))
        {
            pos = pos - (ft_lstsize(stack_a) - i + 1);
            if (count_number_rota(&stack_b, tmp->content) < count)
                return (i);
        }
        if (count_number_rota(&stack_b, tmp->content) == i && i < count && i < count_mediane(stack_a))
            return (i);
		if (count_number_rota(&stack_b, tmp->content) < count || i == 0)
		{
			count = count_number_rota(&stack_b, tmp->content);
            // si count_number_rota_a == count_number_rota et plus petit que les autres rota alors rr 
			x = i;
		}
		if (count == 1)
			break ;
		tmp->content = tmp->next->content;
        // ra_rotate_void(&tmp);
        // tmp = tmp->next;
		i++;
	}
	ft_lstclear(&tmp, free);
	return (x);
}


void	ft_combi_clear(t_list **tmp, t_list **dupli_a)
{
	ft_lstclear(tmp, free);
	ft_lstclear(dupli_a, free);
}

int	big_digit_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*dupli_a;

	tmp = ft_lstduplicate(*stack_b);
	dupli_a = ft_lstduplicate(*stack_a);
	if (tmp->content > biggest_finder(*stack_a))
		push_minimal(stack_a, stack_b);
	else if (condition_papush(&tmp, &dupli_a) == 1)
		pa_push(stack_a, stack_b);
	else if (tmp->content < ft_lstlast(dupli_a)->content
		&& tmp->content > minimal_finder(*stack_a))
		rra_rotate(stack_a);
	else if (tmp->content < dupli_a->content
		&& dupli_a->content == minimal_finder(*stack_a))
		pa_push(stack_a, stack_b);
	else if (tmp->content < dupli_a->content
		&& tmp->content > dupli_a->next->content)
		papush_sa(stack_a, stack_b);
	else if ((tmp->content < dupli_a->content
			&& tmp->content > ft_lstlast(dupli_a)->content))
		pa_push(stack_a, stack_b);
	else
		orga_lst(stack_a);
	ft_combi_clear(&tmp, &dupli_a);
	return (0);
}
