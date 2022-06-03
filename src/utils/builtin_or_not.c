/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/03 16:27:25 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_or_not(void)
{
	if (data.lst && (is_builtin(data.lst->content->val) == 0))
	{
		data.pid = fork();
		if (data.pid == 0)
		{
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
}
