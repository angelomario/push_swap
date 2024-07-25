/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:32:23 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:52:42 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_pilha *a, t_pilha *b)
{
	free(a);
	free(b);
	exit(1);
}

void	set_cheapest(t_pilha *a, t_pilha *b)
{
	t_stack	*tmp;

	tmp = a->top;
	while (tmp)
	{
		tmp->cheapest = get_num_op(tmp, a->tam) + get_num_op(target(b, tmp),
				b->tam);
		tmp = tmp->down;
	}
}

int	op_to_top_target(t_pilha *b, t_stack *element)
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
	tmp = b->top;
	while ((tmp->num != target) && tmp)
		tmp = tmp->down;
	return (tmp->index);
}

int	is_higher(t_stack *element, t_pilha *a)
{
	t_stack	*tmp;

	if (a->tam <= 0)
		return (0);
	if (a->tam == 1)
		return (0);
	tmp = a->top;
	while ((tmp->num <= element->num) && tmp->down)
	{
		tmp = tmp->down;
	}
	return (tmp->num < element->num);
}

char	**ft_no_name_file(char **av, int ac)
{
	char	**mat;
	int		i;

	i = 0;
	mat = (char **)malloc(sizeof(char *) * ac);
	while (--ac)
	{
		mat[i] = ft_strdup(av[i + 1]);
		i++;
	}
	mat[i] = NULL;
	return (mat);
}
