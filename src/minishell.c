/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/25 12:49:21 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
static void	get_env(t_data *data, char **envp)
{
	data->my_env = (char **)0;

	if (data->my_env == (char **)0)
	{
		//ft_putstr_fd("Setting env variable\n", 1);
		init_env(data, envp);
	}
}
*/

int main(int ac, char **av, char **envp)
{
	char	*input;
	int		pid;
	t_data	data;
	char	**Cli;
	t_list	*lst;

	(void)ac;
	(void)av;
	if (!(*envp))
		exit(0);
	init_env(&data, envp);
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, &sigquit_handler);
	while(1)
	{
		// Ca passe a la norme ⏬⏬
		input = readline("MY_PROMPT>> ");
		ctrld_handler(input);
		data.Tokens = str_tok(input, &data);
		Cli = tok_to_cli(data.Tokens, data.tok_nb);
		add_history(input);
		data.Tokens = str_tok(input, &data);
		lst = (*data.Tokens);
		if (lst && (is_builtin(lst->content->val) == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				redir_manager(&data);
				execute(/*Cli[0]*/lst->content->val, &data);
				free(input);
			}
			wait(0);
		}
		else
		{
			redir_manager(&data);
			builtin_manager(&data, 0);
			free(input);
		}
		free_tokens(data.Tokens);
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

/*"🚭\e[0m \e[1;31m\e[3;43m minishell \e[0m  \e[1;36mLamala \e[5;33m⚡\e[0m \e[1;30mChoZeur 🏁\e[0m "*/
