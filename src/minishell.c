/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/09 11:47:16 by tbrebion         ###   ########.fr       */
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
	int		tour = 0;

	(void)ac;
	(void)av;
	pid = fork();
	my_env = get_env(envp);
	//redir_out(av, 0);
    while(1)
	{
		i = 0;
		display_prompt(my_env);
		input = get_next_line(0);
		while (input[i] != '\n')
			i++;
		input[i] = '\0';
		if (is_builtin(input) == 1)
			builtin_manager(input, my_env);
		else
		{
			if (pid == 0) 
				execute(input, my_env);
		}
		tour++;
		ft_printf("\n\nTOUR %d\n\n", tour);
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
