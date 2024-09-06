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

#include "../includes/push_swap_bonus.h"

t_pilha	*ft_init_stack(t_pilha **a, char **av)
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
	return (*a);
}
