/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	here_doc_other_supply(char *line, char *ret)
{
	if (!line)
	{
		free(ret);
		write(2, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

static void	here_doc_supply(char *limiter)
{
	char	*line;
	char	*ret;

	ret = ft_strdup("");
	reinit_sig();
	while (1)
	{
		ft_putstr("here_doc> ");
		line = get_next_line(0);
		here_doc_other_supply(line, ret);
		if ((ft_strncmp(line, limiter, \
		ft_max((ft_strlen(line) - 1), ft_strlen(limiter))) == 0))
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

void	here_doc(void)
{
	pid_t	pid1;
	int		status;

	if (!g_data.lst->next)
	{
		ft_putstr_fd("syntax error\n", 0);
		g_data.error_status = 2;
		exit(g_data.error_status);
		return ;
	}
	ignore_sig();
	pid1 = fork();
	if (pid1 == 0)
		here_doc_supply(g_data.lst->next->content->val);
	waitpid(-1, &status, 0);
	g_data.error_status = WEXITSTATUS(status);
	exit(g_data.error_status);
}
