/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/01 17:43:49 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo) // CTRL+c
{
	if (signo == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		data.error_status = 130;
	}
	set_error_env();

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
	set_error_env();
	//kill(0, SIGINT);
	exit(130);
}
