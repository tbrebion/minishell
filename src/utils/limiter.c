/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/06 10:13:18 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

static void	here_doc_supply(char *limiter)
{
	char	*line;
	char	*ret;

	ret = ft_strdup("");
	signal(SIGINT, &interrupt_cmd);
	while (1)
	{
		ft_putstr("here_doc> ");
		line = get_next_line(0);
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

void	here_doc(char *limiter)
{
	(void)limiter;
	pid_t	pid1;

	signal(SIGINT, SIG_IGN);
	pid1 = fork();
	if (pid1 == 0)
		here_doc_supply(data.lst->next->content->val);
	wait(0);
}
