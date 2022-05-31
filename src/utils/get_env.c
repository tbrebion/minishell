/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/31 14:42:11 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(/*t_data *data, */char **envp)
{
	//char	**my_env;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	if (!(data.my_env = malloc(sizeof(char *) * (i + 4096))))
		exit_shell(data.my_env);//return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!(data.my_env[i] = ft_strdup(envp[i])))
			exit_shell(data.my_env);
		i++;
	}
	//return (data.my_env);
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
