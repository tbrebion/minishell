/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/11 16:00:41 by flcarval         ###   ########.fr       */
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

	(void)ac;
	(void)av;
	(void)envp;
	if (!(*envp))
		exit(0);
	my_env = get_env(envp);
	//cd_builtin(av[1]);
	while(1)
	{
		i = 0;
		input = readline("🚭 \e[0;31mminishell \e[0;36mLamala \e[0;33mChoZeur\e[0m 🏁 ");
		add_history(input);
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
