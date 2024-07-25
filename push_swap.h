/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:44:09 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/19 08:31:16 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_value
{
	int			value_a;
	int			value_b;
	int			index_a;
	int			index_b;
	int			midle_a;
	int			midle_b;
}				t_list_mark;

typedef struct node
{
	int			num;
	int			index;
	int			cheapest;
	int			target;
	struct node	*down;
}				t_stack;

typedef struct slist
{
	t_stack		*top;
	int			tam;
}				t_pilha;

// Prototypes
int				ft_pop(t_pilha *p);
void			ft_push(t_pilha *p, int data);
t_pilha			*ft_creat(t_pilha *p);
// s by a and b
void			sa(t_pilha *a);
void			sb(t_pilha *b);
void			ss(t_pilha *a, t_pilha *b);
// p by a and b
void			pa(t_pilha *a, t_pilha *b);
void			pb(t_pilha *a, t_pilha *b);
// r by a and b
void			ra(t_pilha *a);
void			rb(t_pilha *b);
void			rr(t_pilha *a, t_pilha *b);
// rr by a and b
void			rra(t_pilha *a);
void			rrb(t_pilha *b);
void			rrr(t_pilha *a, t_pilha *b);

// utils
int				ft_strlen(char *str);
char			*ft_strncpy(char *s1, char *s2, int n);
char			**ft_split(char *str);
long int		ft_atoi(char *nptr);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			**ft_no_name_file(char **av, int ac);
void			free_matrix(char **av, int ac);
int				ft_isdigit(int c);
int				ft_error_sintax(char **str);
char			*ft_strncpy(char *s1, char *s2, int n);
int				count_matrix(char **av);
int				is_higher(t_stack *element, t_pilha *a);
int				is_smaller(t_stack *element, t_pilha *a);
int				get_smaller(t_pilha *stack);
int				get_higher(t_pilha *stack);
int				is_sorted(t_pilha *a);
void			set_index(t_pilha *stack);
int				op_to_top_target(t_pilha *b, t_stack *element);
void			rotate(t_pilha *stack);
int				op_to_top_target(t_pilha *b, t_stack *element);
t_stack			*target(t_pilha *p, t_stack *element);
int				get_num_op(t_stack *element, int tam);
void			all_set(t_pilha *a, t_pilha *b);
void			set_mark_a(t_list_mark *mark, t_stack *target_a, t_pilha *a);
void			set_mark_b(t_list_mark *mark, t_stack *target_b, t_pilha *b);
void			set_cheapest(t_pilha *a, t_pilha *b);
int				get_target(t_pilha *b, t_stack *element);
void			set_target(t_pilha *a, t_pilha *b);

// Error
void			free_stack(t_pilha **stack);
void			error_free(t_pilha **a, char **av);
void			ft_init_stack(t_pilha **a, char **av);
int				repeat(t_pilha *a, int len);
void			quit(t_pilha *a, t_pilha *b);

// Sort
void			sort_in_3_or_minus(t_pilha **a);
void			sort_in_5_and_4(t_pilha **a, t_pilha **b);
// void	push_swap(t_pilha *a, t_pilha *b);
void			sort_general(t_pilha **a, t_pilha **b);

#endif
