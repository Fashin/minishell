# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeauvoi <cbeauvoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 11:08:40 by cbeauvoi          #+#    #+#              #
#    Updated: 2017/07/19 18:46:48 by cbeauvoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CFLAGS += -Wall -Wextra -Werror -g

SRCS = 	minishell.c read_standard_input.c search_command.c \
 		puterror.c save_env.c resolve_command.c get_value.c \
		path_cmd.c exec_interne.c convert_env.c ft_echo.c \
		ft_exit.c ft_cd.c list_update.c list_remove.c env.c \
		set_env.c unset_env.c

LIB = ./libft/libft.a
CC = @cc
SRC = $(addprefix src/, $(SRCS))
OBJ = $(SRC:.c=.o)

# COLOR
C_GOOD = "\033[32m"
C_DURING = "\033[36m"
RESET = "\033[00m"

# MESSAGE
SUCCESS = $(C_GOOD)COMPILATION SUCCEEDED

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C libft/
	@echo $(C_DURING)"Compiling" [ $(NAME) . . . ]
	$(CC) $(OBJ) $(LIB) -o $(NAME)
	@echo $(SUCCESS) $(RESET)

cc:
		$(CC) -g $(OBJ) $(LIB) -o $(NAME)

clean:
		@/bin/rm -f $(OBJ)
		@make clean -C libft/
		@echo $(C_GOOD)".o FILES DELETED" $(RESET)

fclean: clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft/
		@echo $(C_GOOD)"EXECUTABLE FILE DELETED" $(RESET)

re: fclean all

leak: fclean $(OBJ)
	@make re -C libft/
	$(CC) $(OBJ) $(LIB) -g -o $(NAME)
