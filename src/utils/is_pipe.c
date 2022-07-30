/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:36:09 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:18 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_pipe(void)
{
	int	i;

	i = 0;
	while (g_data.input[i++])
		if (identify_tok(g_data.input[i]) == I_PIPE)
			return (1);
	return (0);
}
