/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/16 11:00:47 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

static void	here_doc_supply(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	line = "okok";
	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			if ((ft_strncmp(line, limiter, ft_strlen(limiter))) == 0)
				exit(EXIT_SUCCESS);
			line = readline("heredoc> ");
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(0);
	}
}

void	her_doc(char *input)
{
	int		fd;
	int		i;
	char	**split_input;

	i = -1;
	split_input = ft_split(input, ' ');
	fd = open(split_input[1], O_RDONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return ;
	here_doc_supply(split_input[1]);
	while (split_input[++i])
		free(split_input[i]);
	free(split_input);
}


int	main(int ac, char **av)
{
	int	fd;

	(void)ac;
	fd = open(av[1], O_RDONLY | O_CREAT | O_APPEND, 0777); 
	here_doc_supply(av[1]);
}
	