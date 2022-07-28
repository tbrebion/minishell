/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:01:14 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/28 15:55:55 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	actualize_env(void)
{
	char	*oldpwd;
	char	*pwd;
	char	buff[4096];

	oldpwd = ft_strdup("OLDPWD=");
	pwd = ft_strdup("PWD=");
	if (g_data.previous_dir)
	{
		oldpwd = ft_strjoin(oldpwd, g_data.previous_dir);
		set_var(oldpwd);
	}
	free(oldpwd);
	pwd = ft_strjoin(pwd, getcwd(buff, 4095));
	set_var(pwd);
	free(pwd);
}
