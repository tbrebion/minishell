/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:16:36 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/02 16:06:42 by flcarval         ###   ########.fr       */
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

void	display_prompt(void);

// FIND PATH TO EXEC
char	*find_path(char *cmd, char **my_paths);

void	exit_shell(char **my_env);

// UTILS
char	*stradd_char(char *str, char c);

// BUILTINS
void	print_env(char **my_env);

// PARSING
t_tok	*str_tok(char *str);

#endif
