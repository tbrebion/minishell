/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/29 14:26:56 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	g_data;

static void	void_args(int ac, char **av);
static void	main_loop(void);
static void	begin_loop(void);
static int	quote_error(void);

int	main(int ac, char **av, char **envp)
{
	void_args(ac, av);
	init_out_loop(envp);
	main_loop();
	free_split(g_data.my_env);
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
		begin_loop();
		if (!g_data.input[0] || only_white_space() == 1)
			continue ;
		if (quote_error())
			continue ;
		init_in_loop();
		print_tok_list();
		if (rotate_tokens())
			continue ;
		expand_loop();
		g_data.lst = (*g_data.tokens);
		print_tok_list();
		builtin_or_not();
		if (exit_builtin() == 1)
			continue ;
		if (is_cd() || is_export() || is_unset())
		{
			free_loop();
			continue ;
		}
		free_loop();
		set_error_env();
	}
}

static void	begin_loop(void)
{
	set_error_env();
	init_sig();
	g_data.input = readline("\\\\ minishell \\\\ ");
	ctrld_handler(g_data.input);
}

static int	quote_error(void)
{
	if (quotes_not_close() != 1)
		return (0);
	ft_putstr_fd("quotes error\n", 0);
	history();
	return (1);
}
