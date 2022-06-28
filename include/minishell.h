/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:24:08 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/28 10:34:59 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <termio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../Lib42/include/lib42.h"

# define I_LITERAL 100
# define I_SPACE 200
# define I_OUTREDIR 300
# define I_D_OUTREDIR 350
# define I_INREDIR 400
# define I_D_INREDIR 450
# define I_PIPE 500
# define I_S_QUOTE 600
# define I_D_QUOTE 700

# define DEBUG ft_printf("debug\n");

// typedef struct s_tok
// {
// 	char			*val;
// 	int				type;
// }	t_tok;

// extern char	*data.input;

//static struct termios orig_termios;
/*
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
*/
/*
typedef struct cmd_line
{
	char			*cmd;
	struct cmd_line	*next;
}	t_cmd_line;*/

typedef struct s_data
{
	int		tok_nb;
	t_list	**Tokens;
	char	**my_env;
	char	**Cli;
	t_list	*lst;
	int		error_status;
	char	*previous_dir;
	char	*input;
	char	**all_cmd;
	pid_t	pid;
	int		is_env;
}	t_data;

typedef struct	s_directory
{
	char	*cwd;
	char	*home;
	char	*close_to_home;
	char	*tmp;
}	t_directory;

extern t_data	data;
//t_data	* data;

//char	*display_prompt(char **my_env);

// INIT ENV AND ALL PATHS
void	init_env(/*t_data *data, */char **envp);
char	**get_path(char **my_env);
void 	init_in_loop(void);
void 	init_out_loop(char **envp);

// FIND PATH TO EXEC
char	*find_path(char *cmd, char **my_paths);
void	execute(int i);
// void	execute_for_pipe(int i);

// UTILS
char	*stradd_char(char *str, char c);
char	*catch_user(char **my_env);
char	*catch_env_var(char *input/*, t_data *data*/);
int		ft_max(int a, int b);
t_list	*get_n_lst(t_list **Tokens, int n);
void	free_loop(void);
void	set_error_env(void);
void	put_error_status(void);
void	builtin_or_not(void);
int		is_pipe(void);
void	pipe_cmd(void);
int		only_white_space(void);
void	free_split(char **spl);
int		ft_strcmp(char *a, char *b);
char	*ft_strndup(char *s1, int n);
char	*expand_str(char *str);

// BUILTINS
int		is_builtin(char *cmd);
void	builtin_manager(/*t_data *data, */int i);
void	print_cwd(void);
void	exit_shell(char **my_env);
void	print_env(char **my_env);
int		echo_builtin(/*t_data *data, */int i);
void	cd_builtin(/*t_data *data, */int i);
void	export_varenv(/*t_data *data, */int i);
void	unset_builtin(/*t_data *data, */int i);
void	exit_builtin(void);
int		is_cd(void);
int		is_export(void);
int		is_unset(void);


// PARSING
t_list	**str_tok(char *str/*, t_data *data*/);
int		identify_tok(char c);
t_tok	*set_tok(char *str, int *i);
// char	**tok_to_cli(t_list **Tokens, int tok_nb);

//	REDIR
void	redir_manager(/*t_data *data*/);
void	redir_out(char *str);
void	redir_out_append(char *str);
void	redir_in(char *str);
void	here_doc(void);

//	SIGNAL AND EOF HANDLER
void	sigint_handler(int signo);
void	sigquit_handler(int signo);
void	ctrld_handler(char *input);
void	interrupt_cmd(int signo);
void	init_sig(void);
void	reinit_sig(void);
void	ignore_sig(void);

//	 RAW MODE
/*
void disableRawMode(void);
void tty_raw_mode(void);
*/
//int	ft_sig_state(int *status, int get);

#endif
