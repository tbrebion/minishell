# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 16:33:34 by flcarval          #+#    #+#              #
#    Updated: 2022/05/02 13:24:57 by tbrebion         ###   ########.fr        #
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
SRC = $(addprefix src/, minishell.c get_env.c display_prompt.c exit_shell.c exec_test.c)
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
# Generated with GenMake
# Arthur-TRT - https://github.com/arthur-trt/genMake
# genmake vv1.1.4

#Compiler and Linker
CC					:= clang
CXX					:= c++
ifeq ($(shell uname -s),Darwin)
	CC				:= gcc
	CXX				:= g++
endif

#The Target Binary Program
TARGET				:= minishell
TARGET_BONUS		:= minishell-bonus

BUILD				:= release

include sources.mk

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR				:= src
INCDIR				:= include
BUILDDIR			:= obj
TARGETDIR			:= bin
SRCEXT				:= c
DEPEXT				:= d
OBJEXT				:= o

OBJECTS				:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_BONUS		:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_BONUS:.$(SRCEXT)=.$(OBJEXT)))

#Flags, Libraries and Includes
cflags.release		:= -Wall -Werror -Wextra
cflags.valgrind		:= -Wall -Werror -Wextra -DDEBUG -ggdb
cflags.debug		:= -Wall -Werror -Wextra -DDEBUG -ggdb -fsanitize=address -fno-omit-frame-pointer
CFLAGS				:= $(cflags.$(BUILD))
CPPFLAGS			:= $(cflags.$(BUILD)) -std=c++98

lib.release			:=  -L./Lib42 -l42
lib.valgrind		:= $(lib.release)
lib.debug			:= $(lib.release) -fsanitize=address -fno-omit-frame-pointer
LIB					:= $(lib.$(BUILD))

INC					:= -I$(INCDIR) -I/usr/local/include
INCDEP				:= -I$(INCDIR)

# Colors
C_RESET				:= \033[0m
C_PENDING			:= \033[0;36m
C_SUCCESS			:= \033[0;32m

# Multi platforms
ECHO				:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE			:= "\033[1A\033[2K\033[1A"
ERASE				:= $(ECHO) $(ES_ERASE)

GREP				:= grep --color=auto --exclude-dir=.git
NORMINETTE			:= norminette `ls`

# Default Make
all: $(TARGETDIR)/$(TARGET)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

# Bonus rule
bonus: CFLAGS += -DBONUS
bonus: $(TARGETDIR)/$(TARGET_BONUS)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful with bonus! 👌 $(C_RESET)"

# Remake
re: fclean all

# Clean only Objects
clean:
	@$(RM) -f *.d *.o
	@$(RM) -rf $(BUILDDIR)


# Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGETDIR)


# Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# Link
$(TARGETDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

# Link Bonus
$(TARGETDIR)/$(TARGET_BONUS): $(OBJECTS_BONUS)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

$(BUILDIR):
	@mkdir -p $@

# Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@$(ERASE)
	@$(ERASE)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp



norm:
	@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

# Non-File Targets
.PHONY: all re clean fclean norm bonus
