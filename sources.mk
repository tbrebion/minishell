## SOURCES.MK ##

## SRC ##

SOURCES		+=                           		\
		src/minishell.c                     	\


## SRC/UTILS ##

SOURCES		+=                           		\
		src/utils/other_sig_manager.c       	\
		src/utils/builtin_or_not.c          	\
		src/utils/catch_env_var.c           	\
		src/utils/ft_strndup.c              	\
		src/utils/ft_max.c                  	\
		src/utils/stradd_char.c             	\
		src/utils/free_loop.c               	\
		src/utils/get_n_lst.c               	\
		src/utils/only_white_space.c        	\
		src/utils/get_env.c                 	\
		src/utils/signal_manager.c          	\
		src/utils/is_num.c                  	\
		src/utils/exec.c                    	\
		src/utils/expand_str.c              	\
		src/utils/ft_strcmp.c               	\
		src/utils/other_init.c              	\
		src/utils/redir_manager.c           	\
		src/utils/set_error_env.c           	\
		src/utils/limiter.c                 	\
		src/utils/pipe.c                    	\
		src/utils/quotes_not_close.c        	\
		src/utils/free_split.c              	\
		src/utils/redir.c                   	\
		src/utils/here_doc_helper.c         	\
		src/utils/put_error_status.c        	\
		src/utils/is_multi_redir.c          	\
		src/utils/is_pipe.c                 	\
		src/utils/is_space.c                	\
		src/utils/actualize_env.c           	\
		src/utils/expand_loop.c 	          	\


## SRC/BUILTINS ##

SOURCES		+=                           		\
		src/builtins/exit_shell.c           	\
		src/builtins/export_supply.c        	\
		src/builtins/cd_builtin.c           	\
		src/builtins/unset_builtin.c        	\
		src/builtins/export_builtin.c       	\
		src/builtins/pwd_builtin.c          	\
		src/builtins/is_builtin.c           	\
		src/builtins/env_builtin.c          	\
		src/builtins/builtin_manager.c      	\
		src/builtins/echo_builtin.c         	\


## SRC/PARSING ##

SOURCES		+=                           		\
		src/parsing/all_cmd.c               	\
		src/parsing/identify_tok.c          	\
		src/parsing/str_tok.c               	\
		src/parsing/set_tok.c               	\
		src/parsing/set_tok_supply.c        	\


