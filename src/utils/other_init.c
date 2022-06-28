/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:10:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/28 11:04:42 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	history(void)
{
	if (data.input)
		add_history(data.input);
}

void	init_out_loop(char **envp)
{
	data.is_env = 1;
	init_env(envp);
	data.previous_dir = NULL;
	data.error_status = 0;
}

void	init_in_loop(void)
{
	data.Tokens = str_tok(data.input);
	history();
	data.lst = (*data.Tokens);
	// data.Cli = tok_to_cli(data.Tokens, data.tok_nb);
	// data.all_cmd = ft_split(data.input, '|');
}
