/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:32:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/31 15:25:40 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_shell(char **my_env)
{
	int	i;

	i = 0;
	if (my_env[i])
	{
		while (my_env[i])
		{
			free(my_env[i]);
			i++;
		}
		free(my_env);
	}
	exit(EXIT_SUCCESS);
}
