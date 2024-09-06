/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_in_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:46:51 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:48:58 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_num_op(t_stack *element, int tam)
{
	int	midle;

	midle = tam / 2;
	if (midle < element->index)
		return (tam - element->index);
	return (element->index);
}

void	all_set(t_pilha *a, t_pilha *b)
{
	set_cheapest(a, b);
	set_target(a, b);
	set_cheapest(b, a);
	set_target(b, a);
}

void	sort_in_3_or_minus(t_pilha **a)
{
	if ((*a)->tam == 2)
		if (!is_sorted(*a))
			sa(*a);
	if ((*a)->tam == 3)
	{
		while (!is_sorted(*a))
		{
			if (is_higher((*a)->top, *a))
				ra(*a);
			if ((*a)->top->num > (*a)->top->down->num)
				sa(*a);
			if (!is_sorted(*a))
				rra(*a);
		}
	}
}
