/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:41:23 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/17 07:47:48 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_pilha *a, t_pilha *b, t_stack *target_a,
		t_stack *target_b)
{
	t_list_mark	mark;

	set_mark_a(&mark, target_a, a);
	set_mark_b(&mark, target_b, b);
	while ((a->top->num != mark.value_a) && (b->top->num != mark.value_b))
	{
		if ((mark.midle_a <= mark.index_a) && (mark.midle_b <= mark.index_b))
			rrr(a, b);
		else if ((mark.midle_a > mark.index_a) && (mark.midle_b > mark.index_b))
			rr(a, b);
		else
			break ;
	}
	while ((a->top->num != mark.value_a) && (mark.midle_a <= mark.index_a))
		rra(a);
	while ((a->top->num != mark.value_a) && (mark.midle_a > mark.index_a))
		ra(a);
	while (b->top->num != mark.value_b)
	{
		if (mark.midle_b <= mark.index_b)
			rrb(b);
		else
			rb(b);
	}
}

t_stack	*more_cheapest_node(t_pilha *p)
{
	int		cheapest;
	t_stack	*tmp;

	tmp = p->top;
	cheapest = tmp->cheapest;
	while (tmp)
	{
		if (tmp->cheapest < cheapest)
			cheapest = tmp->cheapest;
		tmp = tmp->down;
	}
	tmp = p->top;
	while ((tmp->cheapest != cheapest) && tmp)
		tmp = tmp->down;
	return (tmp);
}

void	move_top_one_a(t_pilha *a, int element)
{
	int		midle;
	int		index;
	t_stack	*tmp;

	tmp = a->top;
	midle = a->tam / 2;
	while (tmp->num != element)
		tmp = tmp->down;
	if (tmp)
		index = tmp->index;
	else
		return ;
	tmp = a->top;
	while (a->top->num != element)
	{
		if (midle <= index)
			rra(a);
		else
			ra(a);
	}
}

void	sort_general(t_pilha **a, t_pilha **b)
{
	pb(*a, *b);
	pb(*a, *b);
	all_set(*a, *b);
	while ((*a)->tam != 1)
	{
		move_to_top(*a, *b, more_cheapest_node(*a),
			target(*b, more_cheapest_node(*a)));
		if (is_higher(more_cheapest_node(*a), *b))
			rb(*b);
		all_set(*a, *b);
		pb(*a, *b);
	}
	sort_in_5_and_4(a, b);
	while ((*b)->tam)
	{
		all_set(*a, *b);
		move_to_top(*a, *b, target(*a, more_cheapest_node(*b)),
			more_cheapest_node(*b));
		if (is_higher(more_cheapest_node(*b), *a))
			ra(*a);
		pa(*a, *b);
	}
	move_top_one_a(*a, get_smaller(*a));
}
