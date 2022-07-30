/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:19:52 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:50:23 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exit_builtin(void)
{
	int	tmp;

	tmp = 0;
	if (!(ft_strncmp(get_n_lst(g_data.tokens, 0)->content->val, "exit", 5)))
	{
		if (get_n_lst(g_data.tokens, 2) && \
		(is_num(get_n_lst(g_data.tokens, 1)->content->val)) == 1)
		{
			ft_putstr_fd("exit\n", 0);
			ft_putstr_fd("exit: too many arguments\n", 0);
			g_data.error_status = 127;
			free_loop();
			return (1);
		}
		exit_supply(tmp);
	}
	return (0);
}

int	is_cd(void)
{
	if (!(ft_strncmp(get_n_lst(g_data.tokens, 0)->content->val, "cd", 3)))
		cd_builtin(0);
	else
		return (0);
	return (1);
}

int	is_export(void)
{
	if (!(ft_strncmp(get_n_lst(g_data.tokens, 0)->content->val, "export", 7)))
		export_varenv(0);
	else
		return (0);
	return (1);
}

int	is_unset(void)
{
	if (!(ft_strncmp(get_n_lst(g_data.tokens, 0)->content->val, "unset", 6)))
		unset_builtin(0);
	else
		return (0);
	return (1);
}

void	builtin_manager(int i)
{
	if (!(ft_strncmp(get_n_lst(g_data.tokens, i)->content->val, "env", 4)) \
		&& !(get_n_lst(g_data.tokens, i + 1)))
		print_env(g_data.my_env);
	else if (!(ft_strncmp(get_n_lst(g_data.tokens, i)->content->val, "env", 4)) \
		&& (get_n_lst(g_data.tokens, i + 1)))
	{
		ft_putstr_fd((get_n_lst(g_data.tokens, i + 1)->content->val), 0);
		ft_putstr_fd(" : No such file or directory\n", 0);
		exit(127);
	}
	if (!(ft_strncmp(get_n_lst(g_data.tokens, i)->content->val, "pwd", 4)))
		print_cwd();
	if (!(ft_strncmp(get_n_lst(g_data.tokens, i)->content->val, "echo", 5)))
		echo_builtin(i);
	if (!(ft_strncmp(get_n_lst(g_data.tokens, i)->content->val, "$?", 3)))
		put_error_status();
}
