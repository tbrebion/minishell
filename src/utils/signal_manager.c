/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/07 16:20:42 by tbrebion         ###   ########.fr       */
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
		exit(EXIT_SUCCESS);
}

void	interrupt_cmd(int signo)
{
	(void)signo;
	data.error_status = 130;
	write(2, "\n", 1);
	exit(130);
}
