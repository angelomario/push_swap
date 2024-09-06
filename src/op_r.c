/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:38:24 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:47:35 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_pilha *stack)
{
	int	*array;
	int	i;
	int	j;
	int	first;

	array = (int *)malloc(sizeof(int) * (stack->tam));
	if (stack->tam > 1)
	{
		first = ft_pop(stack);
		i = -1;
		j = 0;
		while (stack->tam)
			array[++i] = ft_pop(stack);
		ft_push(stack, first);
		while (i >= 0)
		{
			ft_push(stack, array[i--]);
			j++;
		}
	}
	free(array);
}

void	ra(t_pilha *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_pilha *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_pilha *a, t_pilha *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
