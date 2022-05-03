/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:19:52 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/03 11:27:02 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_manager(char *input, char **my_env)
{
	if ((size_t)(strncmp(input, "env\n", ft_strlen(input)) == 0))
		print_env(my_env);
	if ((size_t)(strncmp(input, "exit\n", ft_strlen(input)) == 0))
		exit_shell(my_env);
}
