/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:51:29 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/27 15:04:33 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5) || !ft_strncmp(cmd, "cd", 3) \
		|| !ft_strncmp(cmd, "pwd", 5) || !ft_strncmp(cmd, "export", 7) \
		|| !ft_strncmp(cmd, "unset", 6) || !ft_strncmp(cmd, "env", 5) \
		|| !ft_strncmp(cmd, "exit", 5) || !ft_strncmp(cmd, "$?", 2))
			return (1);
	return (0);
}
