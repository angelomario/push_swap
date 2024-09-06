/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:22:29 by aquissan          #+#    #+#             */
/*   Updated: 2024/09/05 17:23:04 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	verification(char *buffer, t_pilha *a, t_pilha *b)
{
	if (compare_str(buffer, "rra\n"))
		rra(a);
	else if (compare_str(buffer, "rrb\n"))
		rrb(b);
	else if (compare_str(buffer, "ra\n"))
		ra(a);
	else if (compare_str(buffer, "rb\n"))
		rb(b);
	else if (compare_str(buffer, "sb\n"))
		sb(b);
	else if (compare_str(buffer, "sa\n"))
		sa(a);
	else if (compare_str(buffer, "rr\n"))
		rr(a, b);
	else if (compare_str(buffer, "rrr\n"))
		rrr(a, b);
	else if (compare_str(buffer, "pb\n"))
		pb(a, b);
	else if (compare_str(buffer, "pa\n"))
		pa(a, b);
	else if (compare_str(buffer, "ss\n"))
		ss(a, b);
}
