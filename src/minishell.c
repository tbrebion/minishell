/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:43:57 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	data;

static void	void_args(int ac, char **av);
static void	main_loop(void);

int	main(int ac, char **av, char **envp)
{
	void_args(ac, av);
	init_out_loop(envp);
	main_loop();
	free_split(data.my_env);
	return (0);
}

static void	void_args(int ac, char **av)
{
	(void)ac;
	(void)av;
}

static void	main_loop(void)
{
	while (1)
	{
		set_error_env();
		init_sig();
		data.input = readline("MY_PROMPT>> ");
		ctrld_handler(data.input);
		if (!data.input[0] || only_white_space() == 1)
			continue ;
		init_in_loop();
		if (quotes_not_close() == 1)
		{
			ft_putstr_fd("quotes error\n", 0);
			free_loop();
			continue ;
		}
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
}
