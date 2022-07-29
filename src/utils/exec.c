/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:45:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/29 14:39:02 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	execute_supply(char *path, char **cmd);

char	*find_path(char *cmd, char **my_paths)
{
	int		i;
	char	*part_path;
	char	*path;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (my_paths[i])
	{
		part_path = ft_strjoin(my_paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	if (cmd)
	{
		ft_putstr_fd(cmd, 0);
		ft_putstr_fd(" : command not found\n", 0);
	}
	return (NULL);
}

void	execute(int i)
{
	int		pid;
	int		status;
	int		j;
	char	**cmd;

	j = 0;
	pid = fork();
	ignore_sig();
	reinit_sig();
	cmd = NULL;
	if (pid == 0)
	{
		cmd = exec_loop(cmd, i, j);
		g_data.paths = get_path(g_data.my_env);
		g_data.path = find_path(cmd[0], g_data.paths);
		execute_supply(g_data.path, cmd);
	}
	waitpid(-1, &status, 0);
	g_data.error_status = WEXITSTATUS(status);
	exit(g_data.error_status);
}

static void	execute_supply(char *path, char **cmd)
{
	if (!path)
	{
		free_split(cmd);
		exit(127);
	}
	g_data.error_status = 0;
	if (execve(path, cmd, g_data.my_env) == -1)
		exit(130);
}

char	**exec_loop(char **cmd, int i, int j)
{
	cmd = malloc(sizeof(char *) * (g_data.tok_nb + 1));
	if (!cmd)
		return (NULL);
	while (get_n_lst(g_data.tokens, i + j) \
		&& is_lit_or_quotes(get_n_lst(g_data.tokens, i + j)->content))
	{
		cmd[j] = ft_strdup(get_n_lst(g_data.tokens, i + j)->content->val);
		j++;
	}
	cmd[j] = NULL;
	return (cmd);
}
