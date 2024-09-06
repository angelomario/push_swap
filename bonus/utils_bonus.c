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

#include "../includes/push_swap_bonus.h"

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

void	quit(t_pilha *a, t_pilha *b)
{
	free(a);
	free(b);
	exit(1);
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
