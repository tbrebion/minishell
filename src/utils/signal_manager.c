/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/28 10:59:31 by tbrebion         ###   ########.fr       */
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
		data.error_status = 130;
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
		if (data.my_env)
			free_split(data.my_env);
		if (data.previous_dir)
			free(data.previous_dir);
		exit(EXIT_SUCCESS);
	}
}

void	interrupt_cmd(int signo)
{
	(void)signo;
	write(2, "\n", 1);
	exit(130);
}
