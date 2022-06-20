/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:19:52 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/13 16:38:20 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_builtin(void)
{
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, 0)->content->val, "exit", 5) == 0))
	{
		if (get_n_lst(data.Tokens, 1))
		{
			ft_putstr_fd((get_n_lst(data.Tokens, 1)->content->val), 0);
			ft_putstr_fd(": numeric argument required\n", 0);
		}
		exit_shell(data.my_env);
	}
}

int	is_cd(void)
{
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, 0)->content->val, "cd", 3) == 0))
		cd_builtin(0);
	else
		return (0);
	return (1);
}

int	is_export(void)
{
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, 0)->content->val, "export", 7) == 0))
		export_varenv(0);
	else
		return (0);
	return (1);
}

int	is_unset(void)
{
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, 0)->content->val, "unset", 6) == 0))
		unset_builtin(0);
	else
		return (0);
	return (1);
}

void	builtin_manager(/*t_data *data, */int i)
{
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "env", 4) == 0) && !(get_n_lst(data.Tokens, i + 1)))
		print_env(data.my_env);
	else if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "env", 4) == 0) && (get_n_lst(data.Tokens, i + 1)))
	{
		ft_putstr_fd((get_n_lst(data.Tokens, i + 1)->content->val), 0);
		ft_putstr_fd(" : No such file or directory\n", 0);
	}
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "pwd", 4) == 0))
		print_cwd();
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "echo", 5) == 0))
		echo_builtin(/*data, */i);
	// if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "export", 7) == 0))
	// 	export_varenv(/*data, */i);
	// if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "unset", 6) == 0))
	// 	unset_builtin(/*data, */i);
	if ((size_t)(ft_strncmp(get_n_lst(data.Tokens, i)->content->val, "$?", 3) == 0))
		put_error_status();
}
