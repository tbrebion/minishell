/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:51:29 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/27 10:38:52 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 4) || !ft_strncmp(cmd, "cd", 2) \
		|| !ft_strncmp(cmd, "pwd", 3) || !ft_strncmp(cmd, "export", 6) \
		|| !ft_strncmp(cmd, "unset", 5) || !ft_strncmp(cmd, "env", 3) \
		|| !ft_strncmp(cmd, "exit", 4) || !ft_strncmp(cmd, "$?", 2))
		{
			ft_printf("consider as builtin\n");
			return (1);
		}
	return (0);
}
