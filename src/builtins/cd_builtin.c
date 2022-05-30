/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/30 09:45:18 by tbrebion         ###   ########.fr       */
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

	cwd = NULL;
	cwd = getcwd(cwd, 4096);
	close_to_home = ft_strdup("/mnt/nfs/homes/");
	home = ft_strjoin(close_to_home, catch_env_var("$USER", data));
	closedir((DIR *)cwd);
	if (!(get_n_lst(data->Tokens, i + 1)/*->content->val*/))
	{
		if (chdir(home/*"/mnt/nfs/homes/tbrebion"*/) == -1)
			return ;
		return ;
	}
	if (chdir(get_n_lst(data->Tokens, i + 1)->content->val) == -1)
	{
		perror(get_n_lst(data->Tokens, i + 1)->content->val);
		return ;
	}
}
