/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:33:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 11:46:34 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_builtin(int i)
{
	int		j;
	char	**spl;
	char	*var;

	j = 0;
	if (!get_n_lst(data.Tokens, i + 1))
		return ;
	var = get_n_lst(data.Tokens, i + 1)->content->val;
	while (data.my_env[j])
	{
		spl = ft_split(data.my_env[j], '=');
		if (!strncmp(var, spl[0], ft_strlen(var) + 1))
		{
			while (data.my_env[j + 1])
			{
				if (data.my_env[j + 1])
					data.my_env[j] = data.my_env[j + 1];
				j++;
			}
			free(data.my_env[j]);
			data.my_env[j] = NULL;
		}
		free_split(spl);
		j++;
	}
}
