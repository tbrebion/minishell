/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/03 14:23:51 by tbrebion         ###   ########.fr       */
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
t_data	data;

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	init_sig();
	init_env(envp);
	init_out_loop();
	while(1)
	{
		set_error_env();
		data.input = readline("MY_PROMPT>> ");
		ctrld_handler(data.input);
		if(!data.input[0])
			continue ;
		init_in_loop();
		builtin_or_not();
		free_tokens(data.Tokens);
		set_error_env();
	}
	return (0);
}

/*"🚭\e[0m \e[1;31m\e[3;43m minishell \e[0m  \e[1;36mLamala \e[5;33m⚡\e[0m \e[1;30mChoZeur 🏁\e[0m "*/
