/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:03:10 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/24 17:20:13 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	set_simple(char *str, int *i, t_tok *tok);
static void	set_redir(char *str, int *i, t_tok *tok);
static void	set_lit(char *str, int *i, t_tok *tok);
static void	set_quotes(char *str, int *i, t_tok *tok);

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
	/////////////////////////////////////////
	// ft_printf("tok->val = %s\n", tok->val);
	// ft_printf("tok->type = %d\n", tok->type);
	/////////////////////////////////////////
	return (tok);
}

static void	set_simple(char *str, int *i, t_tok *tok)
{
	if (tok->type == I_SPACE)
	{
		tok->val = ft_strdup(" ");
		*i += 1;
	}
	else if (tok->type == I_PIPE)
	{
		tok->val = ft_strdup("|");
		*i += 1;
	}
	else
		set_redir(str, i, tok);
}

static void	set_lit(char *str, int *i, t_tok *tok)
{
	int	len;

	if (tok->type == I_LITERAL)
	{
		// tok.val = str up to a non-literal char
		len = 0;
		while (str[len + *i] && identify_tok(str[len + *i]) == I_LITERAL)
			len++;
		tok->val = malloc(sizeof(char) * (len + 2));
		if (!tok->val)
			return ;
		len = 0;
		while (str[len + *i] && identify_tok(str[len + *i]) == I_LITERAL)
		{
			tok->val[len] = str[len + *i];
			len++;
		}
		tok->val[len] = '\0';
		*i += len;
	}
}

static void	set_quotes(char *str, int *i, t_tok *tok)
{
	int	len;

	// tok.val = str up to SQ or DQ (w/o quotes)
	len = 0;
	while (str[len + *i] && identify_tok(str[len + *i]) != tok->type)
		len++;
	tok->val = malloc(sizeof(char) * (len + *i));
	if (!tok->val)
		return ;
	len = 1;	// to skip first char (that is a quote)
	while (str[len + *i] && identify_tok(str[len + *i]) != tok->type)
	{
		tok->val[len - 1] = str[len + *i];
		len++;
	}
	tok->val[len - 1] = '\0';
	*i += len + 1;
}

static void	set_redir(char *str, int *i, t_tok *tok)
{
	if (tok->type == I_OUTREDIR)
	{
		if (str[*i + 1] == '>')
		{
			tok->val = ft_strdup(">>");
			tok->type = I_D_OUTREDIR;
		}
		else
			tok->val = ft_strdup(">");
		*i += ft_strlen(tok->val);
	}
	else if (tok->type == I_INREDIR)
	{
		if (str[*i + 1] == '<')
		{
			tok->val = ft_strdup("<<");
			tok->type = I_D_INREDIR;
		}
		else
			tok->val = ft_strdup("<");
		*i += ft_strlen(tok->val);
	}
}
