/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/31 11:17:16 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	A LA PLACE DE tbrebion  --> $USER
*/
void	cd_builtin(t_data *data, int i)
{
	char	*cwd;
	char	*home;
	char	*close_to_home;
	static char	*previous_dir = NULL;

	cwd = NULL;
	cwd = getcwd(cwd, 4096);
	close_to_home = ft_strdup("/mnt/nfs/homes/");
	home = ft_strjoin(close_to_home, catch_env_var("$USER", data));
	closedir((DIR *)cwd);
	/////////////////////////////////
	ft_printf("prev = %s\n", previous_dir);
	/////////////////////////////////
	if (!(get_n_lst(data->Tokens, i + 1)))
	{
		if (chdir(home) == -1)
		{
			previous_dir = ft_strdup(cwd);
			data->error_status = 1;
			return ;
		}
		previous_dir = ft_strdup(cwd);
	}
	else if (!ft_strncmp(get_n_lst(data->Tokens, i + 1)->content->val, "-", 2))
	{
		if (previous_dir != NULL)
			chdir(previous_dir);
		return ;
	}
	else if (chdir(get_n_lst(data->Tokens, i + 1)->content->val) == -1)
	{
		perror(get_n_lst(data->Tokens, i + 1)->content->val);
		previous_dir = ft_strdup(cwd);
		data->error_status = 1;
		return ;
	}
}
