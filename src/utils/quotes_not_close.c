/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_not_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:28:54 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/03 14:53:48 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quotes_not_close(void)
{
	int		i;

	i = 0;
	while (data.input[i])
	{
		if (data.input[i] == '\'')
		{
			i++;
			while (data.input[i] && data.input[i] != '\'')
				i++;
			if (data.input[i] != '\'')
				return (1);
		}
		if (data.input[i] == '\"')
		{
			i++;
			while (data.input[i] && data.input[i] != '\"')
				i++;
			if (data.input[i] != '\"')
				return (1);
		}
		i++;
	}
	return (0);
}
