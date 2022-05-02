/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/02 15:25:18 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**get_env(char	**envp)
{
	static char	**my_env = (char **)0;

	if (my_env == (char **)0)
	{
		ft_putstr_fd("Setting env variable\n", 1);
		my_env = init_env(envp);
	}
	else
	{
		ft_putstr_fd("Already setted\n", 1);
	}
	return (my_env);
}


int main(int ac, char **av, char **envp)
{
	char	*input;
	//char	**my_paths;
	char	**my_env;

	(void)ac;
	(void)av;
	(void)envp;
	my_env = get_env(envp);
	//printf("%p\n", get_env(envp));
	//my_paths = get_path();
    while(1)
	{
		char *exit = "exit\n";
		char *env_b = "env\n";
		display_prompt();
		ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
		ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
		input = get_next_line(0);
		if (input == env_b)
			print_env(my_env);
		else if (input == exit)
			exit_shell(my_env);
    }
	return (0);
}
