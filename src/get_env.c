/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:25:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/27 12:30:12 by tbrebion         ###   ########.fr       */
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
