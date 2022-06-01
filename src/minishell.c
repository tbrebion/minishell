/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/01 16:38:51 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static void	get_env(/*t_data *data, */char **envp)
// {
// 	data.my_env = (char **)0;

// 	if (data.my_env == (char **)0)
// 	{
// 		//ft_putstr_fd("Setting env variable\n", 1);
// 		init_env(data, envp);
// 	}
// }


// char	*data.input;
t_data	data;

int main(int ac, char **av, char **envp)
{
	//char	*input;
	int		pid;
	//int		status;
	// t_data	data;
	char	**Cli;
	t_list	*lst;

	(void)ac;
	(void)av;
	if (!(*envp))
		exit(0);
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, &sigquit_handler);
	init_env(/*&data, */envp);
	data.previous_dir = NULL;
	while(1)
	{
		data.input = readline("MY_PROMPT>> ");
		ctrld_handler(data.input);
		if(!data.input[0])
			continue ;
		data.Tokens = str_tok(data.input/*, &data*/);
		Cli = tok_to_cli(data.Tokens, data.tok_nb);
		add_history(data.input);
		data.Tokens = str_tok(data.input/*, &data*/);
		lst = (*data.Tokens);
		if (lst->content->type == I_D_INREDIR)
			here_doc(lst->next->content->val);
		if (lst && (is_builtin(lst->content->val) == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				redir_manager(&data);
				execute(0);
				free(data.input);
				exit(0);
			}
			wait(0);
		}
		else
		{
			redir_manager(&data);
			builtin_manager(0);
			free(data.input);
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
