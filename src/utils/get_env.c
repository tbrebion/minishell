/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:11 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(char **envp)
{
	int		i;

	i = 0;
	g_data.my_env = ft_calloc(4096, sizeof(char *));
	if (!g_data.my_env)
		exit_shell(g_data.my_env, -12);
	while (envp[i])
	{
		g_data.my_env[i] = ft_strdup(envp[i]);
		if (!(g_data.my_env[i]))
			exit_shell(g_data.my_env, -12);
		i++;
	}
	while (g_data.my_env[i++])
		g_data.my_env[i] = NULL;
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
