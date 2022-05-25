/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:33:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/25 14:28:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	unset_builtin(t_data *data, int i)
// {
// 	int	j;

// 	j = 0;
// 	while (data->my_env[j])
// 	{
// 		if (ft_strncmp(data->my_env[j], ft_strjoin(get_n_lst(data->Tokens, i + 1)->content->val, "="), \
// 			ft_strlen(get_n_lst(data->Tokens, i + 1)->content->val) + 1))
// 			{
// 				while (data->my_env[j + 1])
// 				{
// 					data->my_env[j] = data->my_env[j + 1];
// 					j++;
// 				}
// 				data->my_env[j] = NULL;
// 			}
// 			j++;
// 	}
// }

static void	free_split(char **spl);

void	unset_builtin(t_data *data, int i)
{
	int		j;
	char	**spl;
	char	*var;

	j = 0;
	spl = NULL;
	var = get_n_lst(data->Tokens, i)->content->val;
	while (data->my_env[j])
	{
		spl = ft_split(data->my_env[j], '=');
		if (!strncmp(var, spl[0], ft_strlen(var) + 1))
		{
			while (data->my_env[j])
			{
				if (data->my_env[j + 1])
					data->my_env[j] = data->my_env[j + 1];
				j++;
			}
			data->my_env[j] = NULL;
			return ;
		}
		free_split(spl);
		j++;
	}
}

static void	free_split(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}
