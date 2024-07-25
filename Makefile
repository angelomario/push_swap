# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquissan <aquissan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 18:16:36 by aquissan          #+#    #+#              #
#    Updated: 2024/07/19 08:45:31 by aquissan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#FONTS
SRC = ft_init_stack.c op_rr.c utils2.c push_swap_in_5.c sort.c utils3.c ft_error.c main.c op_r.c op_s_p.c push_swap_in_3.c push_swap_init.c stack_change.c utils.c
OBJS = $(SRC:.c=.o)

#DELETE FLAGS
RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o:%.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
