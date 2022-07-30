/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:37:33 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:50:33 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_env(char **my_env)
{
	int	i;

	i = 0;
	while (my_env[i])
	{
		ft_printf("%s\n", my_env[i]);
		i++;
	}
}
