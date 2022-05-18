/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:33:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/18 12:32:08 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_builtin(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->my_env[j])
	{
		if (ft_strncmp(data->my_env[j], ft_strjoin(get_n_lst(data->Tokens, i + 1)->content->val, "="), \
			ft_strlen(get_n_lst(data->Tokens, i + 1)->content->val) + 1))
			{
				while (data->my_env[j + 1])
				{
					data->my_env[j] = data->my_env[j + 1];
					j++;
				}
				data->my_env[j] = NULL;
			}
			j++;
	}
}
