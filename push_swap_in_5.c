/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:07 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/16 17:45:26 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smaller(t_stack *element, t_pilha *a)
{
	t_stack	*tmp;

	if (a->tam <= 0)
		return (0);
	if (a->tam == 1)
		return (0);
	tmp = a->top;
	while ((tmp->num >= element->num) && tmp->down)
	{
		tmp = tmp->down;
	}
	return (tmp->num > element->num);
}

static int	smaller_in_midle(t_pilha *a)
{
	t_stack	*tmp;

	tmp = a->top;
	if ((a)->tam == 4)
		return (0);
	else
	{
		tmp = tmp->down;
		tmp = tmp->down;
		if (is_smaller(tmp, a))
			return (1);
	}
	return (0);
}

void	sort_in_5_and_4(t_pilha **a, t_pilha **b)
{
	int	tam;

	tam = (*a)->tam;
	while (((*a)->tam != 3))
	{
		if (is_sorted(*a))
			break ;
		else
		{
			if (is_smaller((*a)->top, *a))
				pb(*a, *b);
			else if (is_smaller((*a)->top->down, *a) || smaller_in_midle(*a))
				ra(*a);
			else
				rra(*a);
		}
	}
	sort_in_3_or_minus(a);
	while ((*a)->tam != tam)
		pa(*a, *b);
}
