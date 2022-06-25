/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/25 14:44:24 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	data;

static void	void_args(int ac, char **av)
{
	(void)ac;
	(void)av;
}

int main(int ac, char **av, char **envp)
{
	void_args(ac, av);
	data.is_env = 1;
	init_env(envp);
	init_out_loop();
	while (1)
	{
		set_error_env();
		init_sig();
		data.input = readline("MY_PROMPT>> ");
		ctrld_handler(data.input);
		if(!data.input[0] || only_white_space() == 1)
			continue ;
		init_in_loop();
		exit_builtin();
		if (is_cd() || is_export() || is_unset())
		{
			free_loop();
			continue ;
		}
		builtin_or_not();
		free_loop();
		set_error_env();
	}
	free_split(data.my_env);
	return (0);
}

/*"🚭\e[0m \e[1;31m\e[3;43m minishell \e[0m  \e[1;36mLamala \e[5;33m⚡\e[0m \e[1;30mChoZeur 🏁\e[0m "*/
