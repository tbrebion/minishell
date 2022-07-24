/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:21:49 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/21 13:21:47 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redir_in(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror(str);
		g_data.error_status = 1;
	}
	dup2(fd, 0);
	return ;
}

void	redir_out(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	dup2(fd, 1);
	return ;
}

void	redir_out_append(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return ;
	dup2(fd, 1);
	return ;
}
