/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:45:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/27 18:14:18 by flcarval         ###   ########.fr       */
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
	char	*tmp;
	char	**cmd;
	char	**paths;
	char	*path;

	j = 0;
	pid = fork();
	ignore_sig();
	reinit_sig();
	if (pid == 0)
	{
		tmp = ft_strdup("");
		while (get_n_lst(g_data.tokens, i + j) && \
			(get_n_lst(g_data.tokens, i + j)->content->type == I_LITERAL || \
			get_n_lst(g_data.tokens, i + j)->content->type == I_S_QUOTE || \
			get_n_lst(g_data.tokens, i + j)->content->type == I_D_QUOTE))
		{
			if (is_space(get_n_lst(g_data.tokens, /*i + j*/0)->content->val))
			{
				ft_putstr_fd(get_n_lst(g_data.tokens, i)->content->val, 0);
				ft_putstr_fd(" : command not found\n", 0);
				// return ;
				exit(127);
			}
			if (j)
				tmp = ft_strjoin(tmp, " ");
			tmp = ft_strjoin(tmp, get_n_lst(g_data.tokens, i + j)->content->val);
			j++;
		}
		cmd = ft_split(tmp, ' ');
		free(tmp);
		paths = get_path(g_data.my_env);
		path = find_path(cmd[0], paths);
		execute_supply(path, cmd);
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
