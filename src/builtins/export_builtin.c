/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/18 10:53:25 by flcarval         ###   ########.fr       */
=======
/*   Updated: 2022/05/18 09:48:38 by tbrebion         ###   ########.fr       */
>>>>>>> 224377f4b67153900ca7f3b60b82a1ca483c6289
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_varenv(t_data *data, int i)
{
	int		j;

<<<<<<< HEAD
	j = 0;
	while (data->my_env[j])
		j++;
	data->my_env[j] = ft_strdup(data->Tokens[i + 1]->content->val);
=======
	i = 0;
	split_var = ft_split(var_env, ' ');
	while (my_env[i])
		i++;
	my_env[i] = ft_strdup(split_var[1]);	
	// FREE SPLIT_INPUT
>>>>>>> 224377f4b67153900ca7f3b60b82a1ca483c6289
}
