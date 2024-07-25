/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:42:08 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/16 17:07:47 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char *) * ft_strlen(src) + 1);
	if (!(dest))
		return (NULL);
	while (*src)
	{
		dest[i++] = *src++;
	}
	dest[i] = '\0';
	return (dest);
}

// Get the smallest node
int	get_smaller(t_pilha *stack)
{
	int			smaller;
	t_stack		*tmp;

	if (stack->tam == 0)
		return (0);
	smaller = INT_MAX;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->num < smaller)
		{
			smaller = tmp->num;
			tmp = stack->top;
		}
		tmp = tmp->down;
	}
	return (smaller);
}

int	get_higher(t_pilha *stack)
{
	int			smaller;
	t_stack		*tmp;

	if (stack->tam == 0)
		return (0);
	smaller = INT_MIN;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->num > smaller)
		{
			smaller = tmp->num;
			tmp = stack->top;
		}
		tmp = tmp->down;
	}
	return (smaller);
}

int	count_matrix(char **av)
{
	int	i;

	i = 0;
	if (!av || *av == NULL)
		return (0);
	while (av[i])
		i++;
	return (i);
}
