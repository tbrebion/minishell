/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:30:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/23 14:26:23 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*static int	nb_cmd_to_exec(void)
{
	int	nb;

	nb = 0;
	while (data.all_cmd[nb])
		nb++;
	return (nb);
}*/

static void	execute_for_pipe(int i)
{
	int		j;
	// char	*tmp;
	char	**cmd;
	char	**paths;
	char	*path;

	j = -1;
	/*tmp = ft_strdup("");
	while (get_n_lst(data.Tokens, i + j) && \
		get_n_lst(data.Tokens, i + j)->content->type == I_LITERAL)
	{
		if (j)
			tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, get_n_lst(data.Tokens, i + j)->content->val);
		j++;
	}*/
	cmd = ft_split(data.all_cmd[i], ' ');

	// free(tmp);
	paths = get_path(data.my_env);
	path = find_path(cmd[0], paths);
	// j = -1;
	if (!path)
	{
		while (cmd[++j])
			free(cmd[j]);
		free(cmd);
		exit(127);
	}
	data.error_status = 0;
	if (execve(path, cmd, data.my_env) == -1)
		exit(130);
}
/*
static void	child_process(int i)
{
	int	pid;
	// int status;
	int	fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		// redir_manager(&data);
		// if (is_builtin(data.lst->content->val) == 0)
		execute_for_pipe(i);
		// else
			// builtin_manager(i);
		exit(0);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		wait(0);
		// redir_manager(&data);
		// waitpid(-1, &status, 0);
		// data.error_status = WEXITSTATUS(status);
	}
}
*/
void	pipe_cmd(void)
{
	// int		i;
	pid_t	pid;
	int		fd[2];
	// int		status;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execute_for_pipe(1);
	}
	/*else
	{*/
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		execute_for_pipe(0);
	// }
	// i = -1;
	// while (++i < 2)
	// {
	// 	child_process(i);
	// 	execute_for_pipe(i);
	// 	waitpid(-1, &status, 0);
	// }
	// waitpid(-1, &status, 0);
	// data.error_status = WEXITSTATUS(status);
	// exit(data.error_status);
}
