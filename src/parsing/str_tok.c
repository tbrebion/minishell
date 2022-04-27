/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:45:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/27 17:13:50 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	identify_tok(char c);
static int	count_tok(char *str);
static int	count_lit(char *str);

t_tok	*str_tok(char *str)
{
	t_tok	*res;
	int		tok_nb;

	tok_nb = count_tok(str);
}

static int	identify_tok(char c)
{
	if (c == ' ')
		return (SPACE);
	else if (c == '>')
		return (OUTREDIR);
	else if (c == '<')
		return (INREDIR);
	else if (c == '|')
		return (PIPE);
	else if (c == '\'')
		return (S_QUOTE);
	else if (c == '\"')
		return (D_QUOTE);
	else if (c == '\0')
		return (0);
	else
		return (LITERAL);
}

static int	count_tok(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		
	}
}
