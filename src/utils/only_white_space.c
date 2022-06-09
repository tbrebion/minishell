/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_white_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:03:26 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/09 10:12:48 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	only_white_space(void)
{
	int	i;

	i = 0;
	while (data.input[i])
	{
		if (data.input[i] != ' ' && data.input[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
