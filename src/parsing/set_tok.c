/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:03:10 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 14:07:18 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_tok	*set_tok(char *str, int *i)
{
	t_tok	*tok;

	tok = malloc(sizeof(t_tok));
	if (!tok)
		return (NULL);
	tok->type = identify_tok(str[*i]);
	if (tok->type == I_LITERAL)
		set_lit(str, i, tok);
	else if (tok->type == I_S_QUOTE || tok->type == I_D_QUOTE)
		set_quotes(str, i, tok);
	else
		set_simple(str, i, tok);
	return (tok);
}
