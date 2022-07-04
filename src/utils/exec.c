/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:45:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:15:05 by flcarval         ###   ########.fr       */
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
	int		j;
	char	*tmp;
	char	**cmd;
	char	**paths;
	char	*path;

	j = 0;
	tmp = ft_strdup("");
	while (get_n_lst(data.Tokens, i + j) && \
		get_n_lst(data.Tokens, i + j)->content->type == I_LITERAL)
	{
		if (j)
			tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, get_n_lst(data.Tokens, i + j)->content->val);
		j++;
	}
	cmd = ft_split(tmp, ' ');
	free(tmp);
	paths = get_path(data.my_env);
	path = find_path(cmd[0], paths);
	execute_supply(path, cmd);
}

static void	execute_supply(char *path, char **cmd)
{
	if (!path)
	{
		free_split(cmd);
		exit(127);
	}
	data.error_status = 0;
	if (execve(path, cmd, data.my_env) == -1)
		exit(130);
}
