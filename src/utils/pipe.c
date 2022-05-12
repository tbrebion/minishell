/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:30:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/12 13:50:40 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_process(char **split_input, char **my_env, int *fd)
{
	int	filein;

	filein = open(split_input[0], O_RDONLY, 0777);
	if (filein == -1)
		return ; //error
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	exexute(split_input[1], my_env);
}

void	parent_process(char **split_input, char **my_env, int *fd)
{
	int	fileout;

	fileout = open(split_input[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		return ; //error
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	exexute(split_input[2], my_env);
}

int	ft_pipe(char **split_input, char **my_env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (-1); // ERROR
	pid = fork();
	if (pid == -1)
		return (-1); // ERROR
	if (pid == 0)
		child_process(split_input, my_env, fd);
	else
		parent_process(split_input, my_env, fd);
	return (0);
}
