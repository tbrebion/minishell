/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:21:49 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/06 11:25:38 by tbrebion         ###   ########.fr       */
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
	dup2(fd, 0);
	if (fd == -1)
		return (-1); ///return error
	return (0);
}

/////   APPEND DOES NOT WORK --> TO FIX ////////

int	redir_out(char **av, int append) //   >
{
	int	fd;

	if (append == 0)
		fd = open(av[2],  O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(av[2],  O_WRONLY | O_CREAT, 0777);
	dup2(fd, 1);
	if (fd == -1)
		return (-1); ///return error
	return (0);
}
