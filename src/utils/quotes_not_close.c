/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_not_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:28:54 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/01 14:03:28 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	supply(int s_q, int d_q, int i);

int	quotes_not_close(void)
{
	int	i;
	int	s_q;
	int	d_q;

	i = 0;
	s_q = 0;
	d_q = 0;
	while(data.input[i] && data.input[i] != '\'' && data.input[i] != '\"')
		i++;
	if (data.input[i] == '\'')
		s_q++;
	else if (data.input[i] == '\"')
		d_q++;
	else
		return (0);	
	if (supply(s_q, d_q, i) == 1)
		return (1);
	return (0);
}

static int	supply(int s_q, int d_q, int i)
{
	i++;
	if (s_q > 0)
	{
		while (data.input[i])
		{
			if (data.input[i] == '\'')
				s_q++;
			i++;
		}
		if (s_q % 2)
			return (1);
		return (0);
	}
	else if (d_q > 0)
	{
		while (data.input[i])
		{
			if (data.input[i] == '\"')
				d_q++;
			i++;
		}
		if (d_q % 2)
			return (1);
		return (0);
	}
	return (0);
}
