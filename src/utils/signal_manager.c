/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_data.error_status = 130;
		set_error_env();
	}
}

void	sigquit_handler(int signo)
{
	if (signo == SIGQUIT)
		write(2, "\b\b  \b\b", 6);
}

void	ctrld_handler(char *input)
{
	if (input == NULL)
	{
		ft_putstr_fd("exit", 0);
		if (g_data.my_env)
			free_split(g_data.my_env);
		if (g_data.previous_dir)
			free(g_data.previous_dir);
		exit(EXIT_SUCCESS);
	}
}

void	interrupt_cmd(int signo)
{
	(void)signo;
	write(2, "\n", 1);
	exit(130);
}
