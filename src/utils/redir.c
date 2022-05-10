/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:21:49 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/10 10:43:02 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	av is for test
	GOT TO USE THE RIGHT TOKEN OF THE INPUT
*/

int	redir_in(char **av) //   <
{
	int fd;

	fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0777); 
	if (fd == -1)
		return (-1); ///return error
	dup2(fd, 0);
	return (0);
}

/////   APPEND DOES NOT WORK --> TO FIX ////////

int	redir_out(char **av) //   >
{
	int	fd;

	fd = open(av[2],  O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (-1); ///return error
	dup2(fd, 1);
	return (0);
}


int	redir_out_append(char **av) //   >>
{
	int	fd;

	fd = open(av[2],  O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return (-1); ///return error
	dup2(fd, 1);
	return (0);
}
