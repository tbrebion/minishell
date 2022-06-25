/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:32:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/25 12:19:05 by tbrebion         ###   ########.fr       */
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
	if (data.previous_dir)
		free(data.previous_dir);
	exit(EXIT_SUCCESS);
}
