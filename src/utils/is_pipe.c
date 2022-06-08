/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:36:09 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/08 09:51:22 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_pipe(void)
{
	int	i;

	i = 0;
	while (data.input[i++])
		if (identify_tok(data.input[i]) == I_PIPE)
			return (1);
	return (0);
}
