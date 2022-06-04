/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/04 16:13:00 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo) // CTRL+c
{
	if (signo == SIGINT /*&& data.pid != 0*/)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		data.error_status = 130;
	}
	//set_error_env();
}

void	sigquit_handler(int signo) // "CTRL+\"
{
	if (signo == SIGQUIT)
	{
		write(2, "\b\b  \b\b", 6);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	ctrld_handler(char *input) // "CTRL+d"
{
	if (input == NULL)
		exit(EXIT_SUCCESS);
}

void	interrupt_here_doc(int signo)
{
	(void)signo;
	data.error_status = 130;
	data.here_doc_founded = 1;
	//wait(0);
	//set_error_env();
	exit(0);
}

void	init_sig(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, &sigquit_handler);
}