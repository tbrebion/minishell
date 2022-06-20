/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/20 09:13:08 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(char **envp)
{
	int		i;

	i = 0;
	data.my_env = ft_calloc(4096, sizeof(char *));
	if (!data.my_env)
		exit_shell(data.my_env);
	if (!(*envp))
	{
		data.is_env = 0;
		return ;
	}
	i = 0;
	while (envp[i])
	{
		data.my_env[i] = ft_strdup(envp[i]);
		if (!(data.my_env[i]))
			exit_shell(data.my_env);
		i++;
	}
	while (data.my_env[i++])
		data.my_env[i] = NULL;
}

char	**get_path(char **my_env)
{
	int		i;
	char	**my_paths;

	i = 0;
	while (ft_strnstr(my_env[i], "PATH", 4) == 0)
		i++;
	my_paths = ft_split(my_env[i] + 5, ':');
	return (my_paths);
}
