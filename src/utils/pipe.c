/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:30:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/09 10:58:12 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*static int	nb_cmd_to_exec(void)
{
	int	nb;

	nb = 0;
	while (data.all_cmd[nb])
		nb++;
	return (nb);
}*/

static void	child_process(int i)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		redir_manager(&data);
		execute(i);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		redir_manager(&data);
		waitpid(pid, NULL, 0);
	}
}

void	pipe_cmd(void)
{
	int	i;

	i = -1;
	while (data.all_cmd[i++])
		child_process(i);
	wait(0);
}
