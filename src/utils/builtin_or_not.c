/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_or_not.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:02 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/08 10:40:16 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_or_not(void)
{
	if (data.lst)
	{
		exit_builtin();
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
			exit(0);
		}
		wait(0);
	}
}
