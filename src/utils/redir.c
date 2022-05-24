/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:21:49 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/24 12:38:35 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	av is for test
	GOT TO USE THE RIGHT TOKEN OF THE INPUT
*/

int	redir_in(char *str) //   <
{
	int fd;

	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1); ///return error
	dup2(fd, 0);
	return (0);
}

int	redir_out(char *str) //   >
{
	int	fd;

	fd = open(str,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1); ///return error
	dup2(fd, 0);
	return (0);
}

int	redir_out_append(char *str) //   >>
{
	int	fd;

	fd = open(str,  O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (-1); ///return error
	dup2(fd, 1);
	return (0);
}
