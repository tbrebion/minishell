/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/27 14:00:56 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_env(char **envp)
{
	int		i;
	char	**my_env;

	i = 0;
	while (envp[i])
		i++;
	if (!(my_env = malloc(sizeof(char *) * i + 1)))
		return (0);
	i = 0;
	while (envp[i])
	{
		my_env[i] = ft_strdup(envp[i]);
		i++;
	}
	my_env[i] = 0;
	return (my_env);
}

char	**get_path(char **my_env)
{
	int		i;
	char	**my_paths;

	i = 0;
	while (ft_strnstr(my_env[i], "PATH", 4) == 0)
		i++;
	my_paths = ft_split(my_env[i] + 5, ':');
	////////////
	//free my_env
	/////////////
	return (my_paths);
}
