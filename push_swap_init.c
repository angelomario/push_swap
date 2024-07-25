/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:53:18 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:10:34 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wdqtd(char *str, char c)
{
	int	i;
	int	qtd;

	i = 0;
	qtd = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			qtd++;
			i++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (qtd);
}

int	ft_strlen2(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_getwd(char *str, char c, int start)
{
	int			i;
	char		*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ((ft_strlen2(str, c, start)) + 1));
	if (!s)
		return (NULL);
	while (str[start] != c && str[start])
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (wdqtd(str, ' ') + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			split[j++] = ft_getwd(str, ' ', i++);
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	split[j] = NULL;
	return (split);
}
