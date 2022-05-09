/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:45:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/09 10:58:09 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	/*while (my_paths[++i])
		free(my_paths[i]);*/
	free(my_paths);
	return (0);
}

void	execute(char *av, char **my_env)
{
	int		i;
	char	**cmd;
	char	*path;

	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], get_path(my_env));
	ft_printf("\n\nCMD:%s\n\n", cmd[0]);
	ft_printf("\n\nPATH:%s\n\n", path);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_printf("\n\nHERE\n\n");
		exit_shell(my_env);
		//error();
	}
	if (execve(path, cmd, my_env) == -1)
		return ;//exit_shell(my_env);
}
