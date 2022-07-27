/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/27 16:31:29 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	builtin_or_not_supply(int *status);

void	builtin_or_not(void)
{
	int	status;

	if (g_data.lst)
	{
		if (g_data.is_env == 0)
		{
			builtin_manager(0);
			return ;
		}
		else
			builtin_or_not_supply(&status);
	}
}

static void	builtin_or_not_supply(int *status)
{
	ignore_sig();
	g_data.pid = fork();
	if (g_data.pid == 0)
	{
		reinit_sig();
		redir_manager();
		if (!((*g_data.tokens)->content->type == I_LITERAL \
			|| (*g_data.tokens)->content->type == I_S_QUOTE \
			|| (*g_data.tokens)->content->type == I_D_QUOTE))
			exit(2);
		else if (is_builtin((*g_data.tokens)->content->val) == 0)
			execute(0);
		else
			builtin_manager(0);
		exit(0);
	}
	waitpid(-1, status, 0);
	g_data.error_status = WEXITSTATUS(*status);
}
