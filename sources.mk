## SOURCES.MK ##

## SRC ##

SOURCES		+=                         		\
		src/minishell.c                   	\


## SRC/UTILS ##

SOURCES		+=                         		\
		src/utils/get_env.c               	\
		src/utils/exec.c             		\
		src/utils/redir.c                 	\
		src/utils/stradd_char.c           	\
		src/utils/catch_env_var.c      	    \
		src/utils/limiter.c          		\
		src/utils/signal_manager.c          \
		src/utils/ft_max.c                  \
		src/utils/get_n_lst.c               \
		src/utils/free_tokens.c             \
		src/utils/redir_manager.c           \


## SRC/BUILTINS ##

SOURCES		+=                         		\
		src/builtins/builtin_manager.c		\
		src/builtins/env_builtin.c        	\
		src/builtins/cwd_builtin.c        	\
		src/builtins/exit_shell.c           \
		src/builtins/is_builtin.c           \
		src/builtins/cd_builtin.c           \
		src/builtins/echo_builtin.c         \
		src/builtins/export_builtin.c       \
		src/builtins/unset_builtin.c       	\


## SRC/DISPLAY ##

#SOURCES		+=                         	\
		src/display/display_prompt.c      	\


## SRC/PARSING ##

SOURCES		+=                         		\
		src/parsing/str_tok.c             	\
		src/parsing/identify_tok.c       	\
		src/parsing/set_tok.c            	\
		src/parsing/tok_to_cli.c         	\


