/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:45:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/29 18:04:12 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int		identify_tok(char c);
static int		count_tok(char *str);
static t_tok	set_tok(char *str, int *i);

t_tok	*str_tok(char *str)
{
	t_tok	*res;
	int		tok_nb;
	int		i;

	tok_nb = count_tok(str);
	res = malloc(sizeof(t_tok) * tok_nb);
	if (!res)
		return (NULL);
	i = 0;
	while (i < tok_nb)
	{
		res[i] = set_tok(str, &i);
		i++;
	}
}

static int	identify_tok(char c)
{
	// added tabs to SPACE type
	if (c == ' ' || c == '\t')
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
		// check if it's a single or double (> || >>)
		if (identify_tok(str[i]) == OUTREDIR)
		{
			if (identify_tok(str[i + 1]) == OUTREDIR)
				i++;
		}
		// check if it's a single or double (< || <<)
		else if (identify_tok(str[i]) == INREDIR)
		{
			if (identify_tok(str[i]) == INREDIR)
				i++;
		}
		// go to end of LITERAL token
		else if (identify_tok(str[i]) == LITERAL)
			while (identify_tok(str[i]) == LITERAL)
				i++;
		res++;
		i++;
	}
	return (res);
}

static t_tok	set_tok(char *str, int *i)
{
	t_tok	res;

	res.type = identify_tok(str[*i]);
	if (res.type == OUTREDIR)
	{
		res.val = ">";
		if (identify_tok(str[*i + 1]) == OUTREDIR)
		{
			(*i)++;
			res.val = ">>";
		}
	}
	else if (res.type == INREDIR)
	{
		res.val = "<";
		if (identify_tok(str[*i + 1]) == INREDIR)
		{
			(*i)++;
			res.val = "<<";
		}
	}
	else if (res.type == SPACE || res.type == PIPE || \
		res.type == S_QUOTE || res.type == D_QUOTE)
	{
		
	}
	else if (res.type == LITERAL)
	{
		while (identify_tok(str[*i]) == LITERAL)
			(*i)++;
	}
	(*i)++;
}
