/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/10 14:21:58 by tbrebion         ###   ########.fr       */
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
	char	**my_env;
	int		i;
	int		pid;
	//char	*prompt;

	(void)ac;
	(void)av;
	if (!(*envp))
		exit(0);
	my_env = get_env(envp);
    while(1)
	{
		i = 0;
		//display_prompt(my_env);
		//prompt = display_prompt(my_env);
		input = readline("./minishell \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
		//input = get_next_line(0);
		/*while (input[i] != '\n')
			i++;
		input[i] = '\0';*/
		if (is_builtin(input) == 0)
		{
			pid = fork();
			if (pid == 0) 
				execute(input, my_env);
			wait(0);
		}
		else
			builtin_manager(input, my_env);
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
