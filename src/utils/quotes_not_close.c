/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_not_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:28:54 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:25 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quotes_not_close(void)
{
	int		i;

	i = 0;
	while (g_data.input[i])
	{
		if (g_data.input[i] == '\'')
		{
			i++;
			while (g_data.input[i] && g_data.input[i] != '\'')
				i++;
			if (g_data.input[i] != '\'')
				return (1);
		}
		if (g_data.input[i] == '\"')
		{
			i++;
			while (g_data.input[i] && g_data.input[i] != '\"')
				i++;
			if (g_data.input[i] != '\"')
				return (1);
		}
		i++;
	}
	return (0);
}
