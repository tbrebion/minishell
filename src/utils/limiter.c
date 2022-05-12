/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/12 14:17:42 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	#####  USE UNLINK  ########
*/

void	limiter(char *input, char *limiter/*, char **my_env*/)
{
	ft_printf("here_doc> ");
	while ((size_t)ft_strncmp(input, limiter, ft_strlen(limiter) != 0))	
	{
		write(1, "\n", 1);
		ft_printf("here_doc> ");
	}
}
	