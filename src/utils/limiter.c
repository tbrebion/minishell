/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/02 17:39:05 by tbrebion         ###   ########.fr       */
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

void	here_doc(char *limiter)
{
	(void)limiter;
	int	status;
	int	pid;
	t_list	*lst;

	lst = (*data.Tokens);
	if (lst->content->type == I_D_INREDIR)
	{
		signal(SIGINT, SIG_IGN);
		pid = fork();
		if (pid == 0)
			here_doc_supply(lst->next->content->val);
		waitpid(pid, &status, 0);
		signal(SIGINT, &sigint_handler);
		//exit(0);
	}
}
