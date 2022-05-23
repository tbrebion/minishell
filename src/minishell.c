/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/23 10:22:26 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**get_env(char	**envp)
{
	static char	**my_env = (char **)0;

	if (my_env == (char **)0)
	{
		//ft_putstr_fd("Setting env variable\n", 1);
		my_env = init_env(envp);
	}
	else
	{
		//ft_putstr_fd("Already setted\n", 1);
	}
	return (my_env);
}


int main(int ac, char **av, char **envp)
{
	char	*input;
	int		pid;
	t_data	data;
	char	**Cli;

	(void)ac;
	(void)av;
	if (!(*envp))
		exit(0);
	data.my_env = get_env(envp);
	while(1)
	{
		signal(SIGINT, &sigint_handler);
		signal(SIGQUIT, &sigquit_handler);
		// Ca passe a la norme ⏬⏬
		input = readline("🚭\e[0m \e[1;31m\e[3;43m minishell \e[0m  \e[1;36mLamala \
\e[5;33m⚡\e[0m \e[1;30mChoZeur 🏁\e[0m ");
		ctrld_handler(input);
		data.Tokens = str_tok(input, &data);
		Cli = tok_to_cli(data.Tokens, data.tok_nb);
		add_history(Cli[0]);
		data.Tokens = str_tok(input, &data);
		//ft_printf("Cli[0] = %s\n", Cli[0]);
		if (is_builtin(Cli[0]) == 0)
		{
			//ft_printf("Cli[0] = %s\n", Cli[0]);
			pid = fork();
			if (pid == 0)
				execute(Cli[0], &data);
			wait(0);
		}
		else
			builtin_manager(&data, 0);
	}
	return (0);
}

/*int	main(int ac, char **av)
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
}*/
