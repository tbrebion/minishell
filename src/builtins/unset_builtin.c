/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:33:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_builtin(int i)
{
	int		j;
	char	**spl;
	char	*var;

	j = 0;
	if (!get_n_lst(g_data.Tokens, i + 1))
		return ;
	var = get_n_lst(g_data.Tokens, i + 1)->content->val;
	while (g_data.my_env[j])
	{
		spl = ft_split(g_data.my_env[j], '=');
		if (!strncmp(var, spl[0], ft_strlen(var) + 1))
		{
			while (g_data.my_env[j + 1])
			{
				if (g_data.my_env[j + 1])
					g_data.my_env[j] = g_data.my_env[j + 1];
				j++;
			}
			free(g_data.my_env[j]);
			g_data.my_env[j] = NULL;
		}
		free_split(spl);
		j++;
	}
}
