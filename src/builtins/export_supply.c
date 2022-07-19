/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_supply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:47:57 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/19 17:09:31 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_var(char *exp);
void	set_var(char *exp);

void	add_var(char *exp)
{
	int		i;
	char	**tmp;

	i = is_al_set(exp);
	tmp = ft_split(exp, '=');
	if (i == -1)
	{
		i = 0;
		while (g_data.my_env[i])
			i++;
		g_data.my_env[i] = ft_strdup(exp);
	}
	else
		g_data.my_env[i] = ft_strjoin(g_data.my_env[i], tmp[1]);
	free_split(tmp);
}

void	set_var(char *exp)
{
	int	i;

	i = is_al_set(exp);
	if (i == -1)
	{
		i = 0;
		while (g_data.my_env[i])
			i++;
	}
	if (g_data.my_env[i])
		free(g_data.my_env[i]);
	g_data.my_env[i] = ft_strdup(exp);
}
