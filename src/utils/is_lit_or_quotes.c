/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lit_or_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:04:45 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/29 01:06:44 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_lit_or_quotes(t_tok *tok)
{
	if (tok->type == I_LITERAL)
		return (1);
	else if (tok->type == I_S_QUOTE)
		return (2);
	else if (tok->type == I_D_QUOTE)
		return (3);
	else
		return (0);
}
