/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/02 09:49:35 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int ac, char **av, char **envp)
{
	char	*input;
	char	**my_paths;

	(void)ac;
	(void)av;
	init_env(envp);
	my_paths = get_path(g_env);
    while(1)
	{
		display_prompt();
		ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
		ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
		input = get_next_line(0);
    }
	return (0);
}
