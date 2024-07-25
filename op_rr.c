/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:43:07 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:48:04 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_pilha *stack)
{
	int	*array;
	int	i;
	int	j;
	int	last;

	array = (int *)malloc(sizeof(int) * (stack->tam));
	if (stack->tam > 1)
	{
		i = -1;
		j = 0;
		while (stack->tam > 1)
			array[++i] = ft_pop(stack);
		last = ft_pop(stack);
		while (i >= 0)
		{
			ft_push(stack, array[i--]);
			j++;
		}
		ft_push(stack, last);
	}
	free(array);
}

void	rra(t_pilha *a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_pilha *b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_pilha *a, t_pilha *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
