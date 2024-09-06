/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:53:25 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:58:02 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_process(t_pilha *a, t_pilha *b, char **argv)
{
	ft_init_stack(&a, argv);
	if (repeat(a, a->tam))
	{
		free_stack(&a);
		free(b);
		write(2, "Error\n", 7);
		exit(1);
	}
	if (a->tam <= 3)
		sort_in_3_or_minus(&a);
	if (a->tam <= 5)
		sort_in_5_and_4(&a, &b);
	if (a->tam > 5)
		if (!is_sorted(a))
			sort_general(&a, &b);
}

int	main(int argc, char *argv[])
{
	t_pilha	*a;
	t_pilha	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit(1);
	a = ft_creat(a);
	b = ft_creat(b);
	if ((argc == 2) && argv[1][0])
		argv = ft_split(argv[1]);
	else if (argc > 2)
		argv = ft_no_name_file(argv, argc);
	if (ft_error_sintax(argv))
	{
		free_matrix(argv, argc - 1);
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		sort_process(a, b, argv);
	free_stack(&a);
	free(b);
	return (0);
}
