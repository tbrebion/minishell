/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:42:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/13 14:19:10 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	put_error_status(void)
{
	char	*error_status;
	// perror(errno);

	error_status = ft_itoa(data.error_status);
	ft_putstr_fd(error_status, 0);
	ft_putstr_fd(": command not found", 0);
	ft_putchar_fd('\n', 0);
	free(error_status);
	exit(127);
}
