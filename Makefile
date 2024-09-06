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
INC = includes
NAME_BONUS = checker_linux
FONTS = src
FONTS_BONUS = bonus
OBJ_FOLDER = objects
OBJ_FB = objects_bonus
#FLAGS
CC = cc
CFLAGS = -I$(INC) -Wall -Wextra -Werror -g
FILES_B = op_s_p_bonus.c stack_change_bonus.c ft_error_bonus.c\
		atoi_bonus.c\
		ft_init_stack_bonus.c verification_bonus.c\
		main_bonus.c utils_bonus.c\
		op_r_bonus.c push_swap_init_bonus.c\
		op_rr_bonus.c free_array_bonus.c
FILES = ft_init_stack.c op_rr.c utils2.c push_swap_in_5.c sort.c\
		utils3.c ft_error.c main.c op_r.c op_s_p.c\
		push_swap_in_3.c push_swap_init.c stack_change.c utils.c
#FONTS
SRC_BONUS = $(addprefix $(FONTS_BONUS)/, $(FILES_B))
SRC = $(addprefix $(FONTS)/, $(FILES))
OBJS = $(addprefix $(OBJ_FOLDER)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_FB)/, $(FILES_B:.c=.o))
#DELETE FLAGS
RM = rm -rf 
RM_FOLDER = rmdir

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(OBJ_FOLDER)/%.o:$(FONTS)/%.c
	@mkdir -p $(OBJ_FOLDER);
	$(CC) -c $< -o $@

$(OBJ_FB)/%.o:$(FONTS_BONUS)/%.c
	@mkdir -p $(OBJ_FB);
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(OBJ_FOLDER)
	$(RM) $(OBJ_FB)

bonus: $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

norm:
	@norminette */*

re: fclean all

.PHONY: all re clean fclean
