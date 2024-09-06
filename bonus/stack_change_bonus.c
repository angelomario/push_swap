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

#include "../includes/push_swap_bonus.h"

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
	return (removed);
}

void	ft_push(t_pilha *p, int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->num = data;
		new->down = p->top;
		p->tam++;
		p->top = new;
	}
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

void	free_matrix(char **av, int ac)
{
	if (av == NULL || *av == NULL)
		return ;
	while (--ac >= 0)
	{
		free(av[ac]);
		av[ac] = NULL;
	}
	free(av);
}

t_pilha	*ft_creat(t_pilha *p)
{
	p = (t_pilha *)malloc(sizeof(t_pilha));
	p->top = NULL;
	p->tam = 0;
	return (p);
}
