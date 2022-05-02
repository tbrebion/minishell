/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:21:49 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/28 14:31:52 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	redir_in(int fd) //   <
{
	int n_fd;

	n_fd = dup2(fd, 0);
	if (n_fd == -1)
		return (-1); ///return error
	return (n_fd);
}

int	redir_out(int fd) //   >
{
	int	n_fd;

	n_fd = dup2(fd, 1);
	if (n_fd == -1)
		return (-1); ///return error
	return (n_fd);
}
