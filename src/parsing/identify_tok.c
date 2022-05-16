/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:04:09 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/16 18:04:44 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	identify_tok(char c)
{
	// added tabs to I_SPACE type
	if (c == ' ' || c == '\t')
		return (I_SPACE);
	else if (c == '>')
		return (I_OUTREDIR);
	else if (c == '<')
		return (I_INREDIR);
	else if (c == '|')
		return (I_PIPE);
	else if (c == '\'')
		return (I_S_QUOTE);
	else if (c == '\"')
		return (I_D_QUOTE);
	else if (c == '\0')
		return (0);
	else
		return (I_LITERAL);
}
