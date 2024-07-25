/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:11:49 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:45:21 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pop(t_pilha *p)
{
	int		removed;
	t_stack	*tmp;

	if (!(p->top || p))
		return (0);
	tmp = p->top;
	removed = p->top->num;
	p->top = p->top->down;
	p->tam--;
	free(tmp);
	set_index(p);
	return (removed);
}

void	ft_push(t_pilha *p, int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->num = data;
		new->cheapest = 0;
		new->index = 0;
		new->target = 0;
		new->down = p->top;
		p->tam++;
		p->top = new;
	}
	set_index(p);
}

int	is_sorted(t_pilha *a)
{
	t_stack	*tmp;

	if ((a->tam == 1) || (a->tam == 0))
		return (1);
	else
		tmp = a->top;
	while (tmp->down)
	{
		if (tmp->num > tmp->down->num)
			return (0);
		tmp = tmp->down;
	}
	return (1);
}

int	get_target(t_pilha *b, t_stack *element)
{
	int		target;
	t_stack	*tmp;

	tmp = b->top;
	target = get_higher(b);
	while (tmp)
	{
		if (tmp->num > element->num)
		{
			if (tmp->num < target)
				target = tmp->num;
		}
		tmp = tmp->down;
	}
	return (target);
}
