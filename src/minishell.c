/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/02 14:51:09 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**get_env_address(char	**envp)
{
	static char	**environnement = (char **)0;

	(void)envp;
	if (environnement == (char **)0)
	{
		ft_putstr_fd("Setting env variable\n", 1);
		environnement = malloc(sizeof(char *) * 1);
	}
	else
	{
		ft_putstr_fd("Already setted\n", 1);
	}
	return (environnement);
}


int main(int ac, char **av, char **envp)
{
//	char	*input;
	//char	**my_paths;

	(void)ac;
	(void)av;
	printf("%p\n", get_env_address(envp));
	printf("%p\n", get_env_address(envp));
	/*init_env(envp);
	my_paths = get_path();
    while(1)
	{
		char *exit = "exit";
		char *env_b = "env";
		display_prompt();
		ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
		ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
		input = get_next_line(0);
		if (input == env_b)
			print_env();
		else if (input == exit)
			exit_shell();
    }*/
	return (0);
}
