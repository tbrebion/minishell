/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/13 16:09:32 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	A LA PLACE DE tbrebion  --> $USER
*/
void	cd_builtin(/*t_data *data, */int i)
{
	char	*cwd;
	char	*home;
	char	*close_to_home;
	char	*tmp;

	cwd = NULL;
	tmp = NULL;
	cwd = getcwd(cwd, 4096);
	tmp = ft_strdup(cwd);
	close_to_home = ft_strdup("/mnt/nfs/homes/");
	home = ft_strjoin(close_to_home, catch_env_var("$USER"/*, &data*/));
	closedir((DIR *)cwd);
	if (!(get_n_lst(data.Tokens, i + 1)))
	{
		if (chdir(home) == -1)
		{
			data.previous_dir = ft_strdup(cwd);
			data.error_status = 1;
			return ;
		}
	}
	else if (!ft_strncmp(get_n_lst(data.Tokens, i + 1)->content->val, "-", 2))
	{
		if (data.previous_dir != NULL)
			chdir(data.previous_dir);
		print_cwd();
	}
	else if (chdir(get_n_lst(data.Tokens, i + 1)->content->val) == -1)
	{
		perror(get_n_lst(data.Tokens, i + 1)->content->val);
		data.error_status = 1;
		return ;
	}
	data.previous_dir = tmp;
	data.error_status = 0;
}
