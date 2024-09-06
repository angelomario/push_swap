/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:34:19 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/16 08:07:29 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sa(t_pilha *a)
{
	int	pop1;
	int	pop2;

	if (a->tam >= 2)
	{
		pop1 = ft_pop(a);
		pop2 = ft_pop(a);
		ft_push(a, pop1);
		ft_push(a, pop2);
	}
}

void	sb(t_pilha *b)
{
	int	pop1;
	int	pop2;

	if (b->tam >= 2)
	{
		pop1 = ft_pop(b);
		pop2 = ft_pop(b);
		ft_push(b, pop1);
		ft_push(b, pop2);
	}
}

void	ss(t_pilha *a, t_pilha *b)
{
	sa(a);
	sb(b);
}

void	pa(t_pilha *a, t_pilha *b)
{
	if (b->tam >= 1)
		ft_push(a, ft_pop(b));
}

void	pb(t_pilha *a, t_pilha *b)
{
	if (a->tam >= 1)
		ft_push(b, ft_pop(a));
}
