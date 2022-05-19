/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:51:29 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/19 10:23:39 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	### TO FIX WORK WITH MORE CHAR THAN CMD ###
*/

int	is_builtin(char *cmd)
{
	int	echo;
	int	cd;
	int	pwd;
	int	export;
	int	unset;
	int	env;
	int	exit;

	echo = ft_strncmp(cmd, "echo", 4);
	cd = ft_strncmp(cmd, "cd", 2);
	pwd = ft_strncmp(cmd, "pwd", 3);
	export = ft_strncmp(cmd, "export", 6);
	unset = ft_strncmp(cmd, "unset", 5);
	env = ft_strncmp(cmd, "env", 3);
	exit = ft_strncmp(cmd, "exit", 4);
	if (echo == 0 || cd == 0 || pwd == 0 || export == 0 || unset == 0
	|| env == 0 || exit == 0)
	{
		// ft_printf("[is_buitin] 1\n");
		return (1);
	}
	// ft_printf("[is_builtin] 0\n");
	return (0);
}
