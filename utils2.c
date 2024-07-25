/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:06:43 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:32:00 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

long int	ft_atoi(char *nptr)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	nb = 0;
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

t_stack	*target(t_pilha *p, t_stack *element)
{
	int		target;
	t_stack	*tmp;

	tmp = p->top;
	target = get_higher(p);
	while (tmp)
	{
		if (tmp->num > element->num)
		{
			if (tmp->num < target)
				target = tmp->num;
		}
		tmp = tmp->down;
	}
	tmp = p->top;
	while ((tmp->num != target) && tmp)
		tmp = tmp->down;
	return (tmp);
}
