/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:27:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 11:12:25 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cd_home(char *home, char *cwd, char *tmp);
static void	cd_previous(void);
static int	cd_error(char *home, int i);

int	cd_builtin(int i)
{
	char	*cwd;
	char	*home;
	char	*close_to_home;
	char	*tmp;
	char	buff[4096];

	tmp = NULL;
	cwd = getcwd(buff, 4096);
	tmp = ft_strdup(cwd);
	close_to_home = ft_strdup("/mnt/nfs/homes/");
	home = ft_strjoin(close_to_home, catch_env_var("$USER"));
	if (!(get_n_lst(data.Tokens, i + 1)))
		return (cd_home(home, cwd, tmp));
	else if (!ft_strncmp(get_n_lst(data.Tokens, i + 1)->content->val, "-", 2))
		cd_previous();
	else if (chdir(get_n_lst(data.Tokens, i + 1)->content->val) == -1)
		return (cd_error(home, i));
	if (data.previous_dir)
		free(data.previous_dir);
	data.previous_dir = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	free(home);
	data.error_status = 0;
	return (0);
}

static int	cd_home(char *home, char *cwd, char *tmp)
{
	if (data.previous_dir)
		free(data.previous_dir);
	data.previous_dir = ft_strdup(cwd);
	free(tmp);
	if (chdir(home) == -1)
	{
		data.error_status = 1;
		free(home);
		return (0);
	}
	free(home);
	return (1);
}

static void	cd_previous(void)
{
	if (data.previous_dir)
		chdir(data.previous_dir);
	print_cwd();
}

static int	cd_error(char *home, int i)
{
	perror(get_n_lst(data.Tokens, i + 1)->content->val);
	data.error_status = 1;
	free(home);
	return (0);
}
