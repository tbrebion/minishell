# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 16:33:34 by flcarval          #+#    #+#              #
#    Updated: 2022/04/27 16:49:17 by flcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################### VARS ###################################
##### COLORS #####
BLUE = \033[0;34m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
##### SOURCES #####
SRC = $(addprefix src/, minishell.c get_env.c)
PARSING = $(addprefix src/parsing/, str_tok.c)
##### NAMES #####
NAME = minishell
##### OBJECTS #####
OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)
##### COMMANDS #####
CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra
################################################################################

####################################### RULES ##################################
##### CALL #####
all: $(NAME)

val: run
	@valgrind --leak-check=full ./minishell

$(NAME): info_making $(OBJ)
	@make re -C ./Lib42
	@$(CC) $(OBJ) -L./Lib42 -l42 -o $(NAME)
	@echo "\n\t\t$(GREEN)✅ $(NAME) is ready ✅\n$(NC)"

.c.o:
	@$(CC) -L./Lib42 -l42 -c $< -o $(<:.c=.o)

run: all clean

clean:
	@echo "\n$(RED)Deleting objects files\n$(NC)"
	@$(RM) $(OBJ)
	@make clean -C ./Lib42
	@echo "\n$(GREEN)-> Objects files deleted\n"

fclean: clean
	@echo "\n$(RED)Deleting runables$(NC)"
	@$(RM) $(NAME)
	@echo "\n$(GREEN)-> Runables deleted\n"

re: fclean all

##### INFOS #####
info_making:
	@echo "\n\t\t🔷 $(BLUE)Making $(NAME)$(NC) 🔷\n"
################################################################################

.PHONY : minishell all run clean fclean re info_making
