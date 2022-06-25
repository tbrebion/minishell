/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/25 15:33:23 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd_builtin(int i)
{
	char	*cwd;
	char	*home;
	char	*close_to_home;
	char	*tmp;
	char	buff[4096];

	cwd = NULL;
	tmp = NULL;
	cwd = getcwd(buff, 4096);
	tmp = ft_strdup(cwd);
	close_to_home = ft_strdup("/mnt/nfs/homes/");
	home = ft_strjoin(close_to_home, catch_env_var("$USER"));
	if (!(get_n_lst(data.Tokens, i + 1)))
	{
		if (chdir(home) == -1)
		{
			data.previous_dir = ft_strdup(cwd);
			data.error_status = 1;
			free(home);
			free(close_to_home);
			return ;
		}
	}
	else if (!ft_strncmp(get_n_lst(data.Tokens, i + 1)->content->val, "-", 2))
	{
		if (data.previous_dir)
			chdir(data.previous_dir);
		print_cwd();
	}
	else if (chdir(get_n_lst(data.Tokens, i + 1)->content->val) == -1)
	{
		perror(get_n_lst(data.Tokens, i + 1)->content->val);
		data.error_status = 1;
		free(home);
		return ;
	}
	if (data.previous_dir)
		free(data.previous_dir);
	data.previous_dir = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	free(home);
	data.error_status = 0;
}
