/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:42:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	put_error_status(void)
{
	char	*error_status;

	error_status = ft_itoa(g_data.error_status);
	ft_putstr_fd(error_status, 0);
	ft_putstr_fd(": command not found", 0);
	ft_putchar_fd('\n', 0);
	free(error_status);
	exit(127);
}
