/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:10:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/26 19:54:52 by tbrebion         ###   ########.fr       */
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
	// g_data.limiter = NULL;
}

void	init_in_loop(void)
{
	g_data.tokens = str_tok(g_data.input);
	history();
	g_data.lst = (*g_data.tokens);
	multi_limiter();
	actualize_env();
}
