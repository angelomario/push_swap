/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:18:12 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:45:39 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack(t_pilha **a, char **av)
{
	long int	nbr;
	int			i;

	i = 0;
	while (av[i] != NULL)
		i++;
	i--;
	while (i >= 0)
	{
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av);
		ft_push(*a, (int)nbr);
		i--;
	}
	free_matrix(av, count_matrix(av));
}

void	set_target(t_pilha *a, t_pilha *b)
{
	t_stack	*tmp;

	tmp = a->top;
	while (tmp)
	{
		tmp->target = get_target(b, tmp);
		tmp = tmp->down;
	}
}

void	set_mark_a(t_list_mark *mark, t_stack *target_a, t_pilha *a)
{
	(*mark).index_a = target_a->index;
	(*mark).midle_a = a->tam / 2;
	(*mark).value_a = target_a->num;
}

void	set_mark_b(t_list_mark *mark, t_stack *target_b, t_pilha *b)
{
	(*mark).index_b = target_b->index;
	(*mark).midle_b = b->tam / 2;
	(*mark).value_b = target_b->num;
}

void	set_index(t_pilha *stack)
{
	int		index;
	t_stack	*tmp;

	index = 0;
	tmp = stack->top;
	while (tmp)
	{
		tmp->index = index++;
		tmp = tmp->down;
	}
}
