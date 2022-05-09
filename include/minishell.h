/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:16:36 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/09 09:58:25 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../Lib42/include/lib42.h"

//char	**g_env;

# define I_LITERAL 100
# define I_SPACE 200
# define I_OUTREDIR 300
# define I_INREDIR 400
# define I_PIPE 500
# define I_S_QUOTE 600
# define I_D_QUOTE 700

typedef struct s_tok
{
	char	*val;
	int		type;
}	t_tok;

typedef struct s_cmd
{
	char	**av;
	t_tok	*redir;
}	t_cmd;

typedef struct s_pipe
{
	t_cmd	*left;
	t_cmd	*right;
}	t_pipe;

// INIT ENV AND ALL PATHS
char	**init_env(char **envp);
char	**get_path(char **my_env);

void	display_prompt(char **my_env);

// FIND PATH TO EXEC
char	*find_path(char *cmd, char **my_paths);
void	execute(char *av, char **my_env);

// UTILS
char	*stradd_char(char *str, char c);
char	*catch_user(char **my_env);
char 	*catch_username(char *user_line);
void	signal_handler(int signo, char **my_env);

// BUILTINS
int		is_builtin(char *cmd);
void	builtin_manager(char *input, char **my_env);
void	print_cwd(void);
void	exit_shell(char **my_env);
void	print_env(char **my_env);
int		echo_builtin(char *str, int n);

// PARSING
t_tok	*str_tok(char *str);

//	REDIR
int		redir_out(char **av, int append);
int		redir_in(char **av);

#endif
