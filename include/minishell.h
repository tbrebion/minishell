/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:16:36 by tbrebion          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/02 11:24:26 by tbrebion         ###   ########.fr       */
=======
/*   Updated: 2022/04/29 19:17:31 by flcarval         ###   ########.fr       */
>>>>>>> 0dae6e9235c13156728579cc00082cf1660704a8
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

<<<<<<< HEAD
char	**g_env;

=======
>>>>>>> 0dae6e9235c13156728579cc00082cf1660704a8
# define LITERAL 100
# define SPACE 200
# define OUTREDIR 300
# define INREDIR 400
# define PIPE 500
# define S_QUOTE 600
# define D_QUOTE 700

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

void	init_env(char **envp);
char	**get_path(char **my_env);
void	display_prompt(void);

<<<<<<< HEAD
char	*find_path(char *cmd, char **my_paths);

void	exit_shell(void);
=======
// UTILS
char	*stradd_char(char *str, char c);
>>>>>>> 0dae6e9235c13156728579cc00082cf1660704a8

#endif
