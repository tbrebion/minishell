## SOURCES.MK ##

## SRC ##

SOURCES		+=                         		\
		src/minishell.c                   	\


## SRC/UTILS ##

SOURCES		+=                         		\
		src/utils/get_env.c               	\
		src/utils/exec_test.c             	\
		src/utils/redir.c                 	\
		src/utils/stradd_char.c           	\


## SRC/BUILTINS ##

SOURCES		+=                         		\
		src/builtins/builtin_manager.c		\
		src/builtins/env_builtin.c        	\
		src/builtins/exit_shell.c           \


## SRC/DISPLAY ##

SOURCES		+=                         		\
		src/display/display_prompt.c      	\


## SRC/PARSING ##

SOURCES		+=                         		\
		src/parsing/str_tok.c             	\


