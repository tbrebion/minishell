/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_white_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:03:26 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	only_white_space(void)
{
	int	i;

	i = 0;
	while (g_data.input[i])
	{
		if (g_data.input[i] != ' ' && g_data.input[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
