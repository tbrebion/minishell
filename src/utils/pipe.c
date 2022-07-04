/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:30:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:38:34 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	execute_for_pipe(int i)
{
	int		j;
	char	**cmd;
	char	**paths;
	char	*path;

	j = -1;
	cmd = ft_split(data.all_cmd[i], ' ');
	paths = get_path(data.my_env);
	path = find_path(cmd[0], paths);
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

void	pipe_cmd(void)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		redir_manager(&data);
		execute_for_pipe(1);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		redir_manager(&data);
		execute_for_pipe(0);
	}
	waitpid(-1, &status, 0);
	data.error_status = WEXITSTATUS(status);
	exit(data.error_status);
}
