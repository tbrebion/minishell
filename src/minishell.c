/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/02 16:07:11 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static char	**get_env(char	**envp)
// {
// 	static char	**my_env = (char **)0;

// 	if (my_env == (char **)0)
// 	{
// 		ft_putstr_fd("Setting env variable\n", 1);
// 		my_env = init_env(envp);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("Already setted\n", 1);
// 	}
// 	return (my_env);
// }


// int main(int ac, char **av, char **envp)
// {
// 	char	*input;
// 	//char	**my_paths;
// 	char	**my_env;

// 	(void)ac;
// 	(void)av;
// 	(void)envp;
// 	my_env = get_env(envp);
// 	//printf("%p\n", get_env(envp));
// 	//my_paths = get_path();
//     while(1)
// 	{
// 		char *exit = "exit\n";
// 		char *env_b = "env\n";
// 		display_prompt();
// 		ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
// 		ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
// 		input = get_next_line(0);
// 		if (input == env_b)
// 			print_env(my_env);
// 		else if (input == exit)
// 			exit_shell(my_env);
//     }
// 	return (0);
// }

int	main(int ac, char **av)
{
	(void)ac;
	t_tok	*Tokens = str_tok(av[1]);
	int i = 0;
	while (Tokens[i].val)
	{
		ft_printf("Token[%d].val = %s\nToken[%d].type = %d\n\n",i, Tokens[i].val, i, Tokens[i].type);
		i++;
	}
	return (0);
}
