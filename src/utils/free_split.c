/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:11 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/27 12:20:32 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_split(char **spl)
{
	int	i;

	i = 0;
	if (!spl)
		return ;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	spl = NULL;
}
