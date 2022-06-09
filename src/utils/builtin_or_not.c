/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/09 16:09:01 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_or_not(void)
{
	if (data.lst)
	{
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
			free(data.input);
			free_loop();
			exit(0);
		}
		wait(0);
	}
}
