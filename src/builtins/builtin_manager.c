/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:19:52 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/17 11:31:56 by flcarval         ###   ########.fr       */
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
	if ((size_t)(ft_strncmp(input, "export", 6) == 0))
		export_varenv(input, my_env);
	if ((size_t)(ft_strncmp(input, "cd", 2) == 0))
		cd_builtin(input);
}
