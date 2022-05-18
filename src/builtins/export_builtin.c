/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/18 11:04:17 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_varenv(t_data *data, int i)
{
	int		j;

	j = 0;
	while (data->my_env[j])
		j++;
	data->my_env[j] = ft_strdup(data->Tokens[i + 1]->content->val);
}
