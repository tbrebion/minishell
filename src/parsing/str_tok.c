/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:45:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/29 16:43:25 by flcarval         ###   ########.fr       */
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
	// added tabs to SPACE type
	if (c == ' ' || '\t')
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
		if (identify_tok(str[i]) == OUTREDIR)
			// check if it's a single or double (> || >>)
			if (identify_tok(str[i + 1]) == OUTREDIR)
				i++;
		else if (identify_tok(str[i]) == INREDIR)
			// check if it's a single or double (< || <<)
			if (identify_tok(str[i]) == INREDIR)
				i++;
		else if (identify_tok(str[i]) == LITERAL)
			// go to end of LITERAL token
			while (identify_tok(str[i]) == LITERAL)
				i++;
		res++;
		i++;
	}
}
