/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:10:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	history(void)
{
	if (g_data.input)
		add_history(g_data.input);
}

void	init_out_loop(char **envp)
{
	g_data.is_env = 1;
	init_env(envp);
	g_data.previous_dir = NULL;
	g_data.error_status = 0;
}

void	init_in_loop(void)
{
	g_data.Tokens = str_tok(g_data.input);
	history();
	g_data.lst = (*g_data.Tokens);
}
