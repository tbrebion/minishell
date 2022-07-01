/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/01 12:19:36 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_or_not(void)
{
	int	status;

	if (data.lst)
	{
		if (data.is_env == 0)
		{
			builtin_manager(0);
			return ;
		}
		else
		{
			// ft_printf("is env : %d\n", data.is_env);
			ignore_sig();
			data.pid = fork();
			if (data.pid == 0)
			{
				reinit_sig();
				redir_manager(&data);
				if (is_builtin(data.lst->content->val) == 0)
						execute(0);
				else
					builtin_manager(0);
				exit(0);
			}
			waitpid(-1, &status, 0);
			data.error_status = WEXITSTATUS(status);
		}
	}
}
