/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/06 12:34:28 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
void	builtin_or_not(void)
{
	if (data.lst && (is_builtin(data.lst->content->val) == 0))
	{
		signal(SIGINT, SIG_IGN);
		data.pid = fork();
		if (data.pid == 0)
		{
			signal(SIGINT, &interrupt_cmd);
			redir_manager(&data);
			execute(0);
			free(data.input);
			exit(0);
		}
		wait(0);
	}
	else
	{
		redir_manager(&data);
		builtin_manager(0);
		free(data.input);
	}
}*/

void	builtin_or_not(void)
{
	if (data.lst)
	{
		signal(SIGINT, SIG_IGN);
		data.pid = fork();
		if (data.pid == 0)
		{
			signal(SIGINT, &interrupt_cmd);
			redir_manager(&data);
			if (is_builtin(data.lst->content->val) == 0)
				execute(0);
			else
				builtin_manager(0);
			free(data.input);
			exit(0);
		}
		wait(0);
	}
}
