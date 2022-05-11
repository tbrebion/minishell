/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/11 11:32:24 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**init_env(char **envp)
{
	char	**my_env;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	if (!(my_env = malloc(sizeof(char *) * i + 1)))
		exit_shell(my_env);//return (NULL);
	i = 0;
	while (envp[i])
	{
		if (!(my_env[i] = ft_strdup(envp[i])))
			exit_shell(my_env);
		i++;
	}
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
	return (my_paths);
}
