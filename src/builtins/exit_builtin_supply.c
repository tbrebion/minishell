/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin_supply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:20:41 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:50:34 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_supply(int tmp)
{
	if (get_n_lst(g_data.tokens, 1))
	{
		tmp = ft_atoi(get_n_lst(g_data.tokens, 1)->content->val);
		if ((is_num(get_n_lst(g_data.tokens, 1)->content->val)) == 0)
		{
			ft_putstr_fd((get_n_lst(g_data.tokens, 1)->content->val), 0);
			ft_putstr_fd(": numeric argument required\n", 0);
			free_loop();
			g_data.error_status = 2;
			exit_shell(g_data.my_env, 2);
		}
		free_loop();
		exit_shell(g_data.my_env, tmp);
	}
	free_loop();
	exit_shell(g_data.my_env, 0);
}
