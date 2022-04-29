/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:16:36 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/29 18:03:22 by tbrebion         ###   ########.fr       */
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

# define LITERAL 100
//# define SPACE 200
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

char	**get_env(char **envp);
char	**get_path(char **my_env);

void	display_prompt(void);

#endif
