/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:45:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/06 17:31:42 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		//free(part_path); // WHY ?
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	data.error_status = 127;
	// while (my_paths[++i])
		// free(my_paths[i]);
	// free(my_paths);
	return (NULL);
}

void	execute(/*char *av, t_data *data, */int i)
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
	cmd = ft_split(/*av*/tmp, ' ');
	free(tmp);
	paths = get_path(data.my_env);
	path = find_path(cmd[0], paths);
	j = -1;
	if (!path)
	{
		ft_printf("%s : ", cmd[0]);
		ft_putstr_fd("command not found\n", 2);
		while (cmd[++j])
			free(cmd[j]);
		free(cmd);
		free_tokens(data.Tokens);
		data.error_status = 127;
		exit(0);
		//exit_shell(data.my_env);
	}
	data.error_status = 0;
	if (execve(path, cmd, data.my_env) == -1)
	{
		//data.error_status = 127;
		perror(cmd[0]);
	}
		//return ;//exit_shell(my_env);
}
