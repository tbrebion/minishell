/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:45:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/29 19:02:55 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int		identify_tok(char c);
static int		count_tok(char *str);
static t_tok	set_tok(char *str, int *i);
static void		set_tok_single_char(t_tok *tok);

t_tok	*str_tok(char *str)
{
	t_tok	*Tok;
	int		tok_nb;
	int		i;

	tok_nb = count_tok(str);
	Tok = malloc(sizeof(t_tok) * tok_nb);
	if (!Tok)
		return (NULL);
	i = 0;
	while (i < tok_nb)
	{
		Tok[i] = set_tok(str, &i);
		i++;
	}
	return (Tok);
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
	t_tok	tok;

	tok.type = identify_tok(str[*i]);
	tok.val = "";
	if (tok.type == OUTREDIR)
	{
		tok.val = ">";
		if (identify_tok(str[*i + 1]) == OUTREDIR)
		{
			(*i)++;
			res.val = ">>";
		}
	}
	else if (tok.type == INREDIR)
	{
		tok.val = "<";
		if (identify_tok(str[*i + 1]) == INREDIR)
		{
			(*i)++;
			tok.val = "<<";
		}
	}
	else if (tok.type == SPACE || tok.type == PIPE || \
		tok.type == S_QUOTE || tok.type == D_QUOTE)
		set_tok_single_char(&tok);
	else if (res.type == LITERAL)
	{
		while (identify_tok(str[*i]) == LITERAL)
		{
			(*i)++;
			tok.val = stradd_char(val, str[*i]);
		}
	}
	(*i)++;
	return (tok);
}

static void	set_tok_single_char(t_tok *tok)
{
	if (tok->type == SPACE)
		tok->val = " ";
	else if (tok->type == PIPE)
		tok->val = "|";
	else if (tok->type == S_QUOTE)
		tok->val = "\'";
	else if (tok->type == D_QUOTE)
		tok->val = "\"";
}
