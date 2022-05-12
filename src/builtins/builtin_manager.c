/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:19:52 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/12 11:01:28 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_manager(char *input, char **my_env)
{
	if ((size_t)(ft_strncmp(input, "env", 3) == 0))
		print_env(my_env);
	if ((size_t)(ft_strncmp(input, "exit", 4) == 0))
		exit_shell(my_env);
	if ((size_t)(ft_strncmp(input, "pwd", 3) == 0))
		print_cwd();
	if ((size_t)(ft_strncmp(input, "echo", 4) == 0))
		echo_builtin(input);
}
