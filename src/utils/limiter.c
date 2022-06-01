/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/01 12:05:46 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

void	here_doc(char *limiter)
{
	char	*line;
	char	*ret;
	int		pid;
	int		status;
	int		i;

	ret = NULL;
	i = 0;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, interrupt_here_doc);
		while (1)
		{
			ft_putstr("here_doc> ");
			line = get_next_line(0);
			//line = readline("here_doc> ");
			if ((ft_strncmp(line, limiter, ft_max((ft_strlen(line) - 1), ft_strlen(limiter))) == 0))
			{
				free(line);
				break ;
			}
			ret = ft_strjoin(ret, line);
			free(line);
		}
		ft_putstr(ret);
		free(ret);
		exit(0);
	}
	waitpid(pid, &status, 0);
}
