/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:10:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/23 11:16:42 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	history(void)
{
	if (data.input)
		add_history(data.input);
}

void	init_out_loop(void)
{
	data.previous_dir = NULL;
	data.error_status = 0;
}

void	init_in_loop(void)
{
	data.Tokens = str_tok(data.input);
	// data.Cli = tok_to_cli(data.Tokens, data.tok_nb);
	history();
	data.lst = (*data.Tokens);
	data.all_cmd = ft_split(data.input, '|');
}
