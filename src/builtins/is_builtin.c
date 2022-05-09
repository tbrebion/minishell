/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:51:29 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/09 10:45:55 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	int	echo;
	int	cd;
	int	pwd;
	int	export;
	int	unset;
	int	env;
	int	exit;

	echo = ft_strncmp(cmd, "echo\n", ft_strlen(cmd));
	cd = ft_strncmp(cmd, "cd\n", ft_strlen(cmd));
	pwd = ft_strncmp(cmd, "pwd\n", ft_strlen(cmd));
	export = ft_strncmp(cmd, "export\n", ft_strlen(cmd));
	unset = ft_strncmp(cmd, "unset\n", ft_strlen(cmd));
	env = ft_strncmp(cmd, "env\n", ft_strlen(cmd));
	exit = ft_strncmp(cmd, "exit\n", ft_strlen(cmd));
	if (echo == 0 || cd == 0 || pwd == 0 || export == 0 || unset == 0 
	|| env == 0 || exit == 0)
		return (1);
	ft_printf("NO BUILTIN");
	return (0);
}
