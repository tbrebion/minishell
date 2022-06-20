/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:11 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/20 16:23:48 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_split(char **spl)
{
	int	i;

	i = 0;
	if (!spl[i])
		return ;
	while (spl[i])
	{
		ft_printf("i = %d\n", i);
		free(spl[i]);
		i++;
	}
	free(spl);
	spl = NULL;
}
