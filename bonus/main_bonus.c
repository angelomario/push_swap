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

#include "../includes/push_swap_bonus.h"

int	compare_str(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0');
}

void	check(t_pilha *a, t_pilha *b, char **av)
{
	char	buffer[1024];

	if (repeat(a, a->tam))
	{
		free_stack(&a);
		free_stack(&b);
		pre_error(4);
	}
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		verification(buffer, a, b);
	}
	if (is_sorted(a))
		printf("\033[32mOK\033[0m\n");
	else
		printf("\033[31mKO\033[0m\n");
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i)
		write (1, str, i);
}

void	pre_error(int alter)
{
	char	buffer[1024];

	if (alter != 1)
		ft_putstr("\033[31mError\033[0m\n");
	if (alter >= 3)
	{
		while (fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			if (compare_str(buffer, "Error\n"))
				ft_putstr(buffer);
		}
	}
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_pilha	*a;
	t_pilha	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		pre_error(argc);
	a = ft_creat(a);
	b = ft_creat(b);
	if ((argc == 2) && argv[1][0])
		argv = ft_split(argv[1]);
	else if (argc > 2)
		argv = ft_no_name_file(argv, argc);
	if (ft_error_sintax(argv))
	{
		free(a);
		free(b);
		free_matrix(argv, argc + 2);
		pre_error(3);
	}
	a = ft_init_stack(&a, argv);
	check(a, b, argv);
	free_stack(&a);
	free(b);
	return (0);
}
