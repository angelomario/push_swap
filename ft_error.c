/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:03:46 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:55:57 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if the *a stack contains repeated numbers
int	error_repeatint(t_pilha *a, int nbr)
{
	t_stack	*tmp;

	tmp = a->top;
	if (!a)
		return (0);
	while (tmp)
	{
		if (tmp->num == nbr)
			return (1);
		tmp = tmp->down;
	}
	return (0);
}

int	repeat(t_pilha *a, int len)
{
	t_stack	*tmp;
	t_stack	*cur;
	int		vez;

	if (a == NULL || len == 0)
		return (0);
	cur = a->top;
	tmp = a->top;
	while (cur)
	{
		vez = 0;
		while (tmp && cur)
		{
			if (tmp->num == cur->num)
				vez++;
			tmp = tmp->down;
		}
		if (vez >= 2)
			return (1);
		cur = cur->down;
		tmp = a->top;
	}
	return (0);
}

int	ft_error_sintax(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][j] && (str[i][j] == '+' || str[i][j] == '-'))
			j++;
		while (str[i][j] && (str[i][j] >= '0' && str[i][j] <= '9'))
			j++;
		if ((str[i][j] != '\0' || j == 0))
			return (1);
		if (str[i][j] == '\0')
		{
			if ((str[i][j - 1] == '+') || (str[i][j - 1] == '-'))
				return (1);
		}
	}
	return (0);
}

void	free_stack(t_pilha **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if ((*stack)->tam == 0)
		return ;
	current = (*stack)->top;
	while (current)
	{
		tmp = current->down;
		free(current);
		current = tmp;
	}
	free(*stack);
}

void	error_free(t_pilha **a, char **av)
{
	free_stack(a);
	free_matrix(av, count_matrix(av));
	write(2, "Error\n", 6);
	exit(1);
}
