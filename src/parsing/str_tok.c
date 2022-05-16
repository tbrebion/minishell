/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/16 14:26:32 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	identify_tok(char c);
static t_tok	*set_tok(char *str, int *i);

t_list	**str_tok(char *str)
{
	t_list	**Tokens;
	int		i;

	// Tokens = NULL;
	Tokens = malloc(sizeof(t_list *));
	if (!Tokens)
		return (NULL);
	*Tokens = NULL;
	i = 0;
	while (str[i])
	{
		ft_printf("i = %d\n", i);
		ft_lstadd_back(Tokens, ft_lstnew((t_tok *)set_tok(str, &i)));
	}
	return (Tokens);
}

int	main(int ac, char **av)
{
	t_list	**Tokens;
	t_list	*lst;
	t_list	*prev;

	(void)ac;
	Tokens = str_tok(av[1]);
	lst = *Tokens;
	while (lst)
	{
	/////////////////////////////////////////
		ft_printf("tok.type = %d\ttok.val = %s\n", lst->content->type, lst->content->val);
	/////////////////////////////////////////
		prev = lst;
		lst = lst->next;
		free(prev->content->val);
		free(prev);
	}
	return (0);
}

static int	identify_tok(char c)
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

static t_tok	*set_tok(char *str, int *i)
{
	t_tok	*tok;
	int		len;

	tok = malloc(sizeof(t_tok));
	if (!tok)
		return (NULL);
	tok->type = identify_tok(str[*i]);
	/////////////////////////////////////////
	ft_printf("tok->type = %d\n", tok->type);
	/////////////////////////////////////////
	if (tok->type == I_LITERAL)
	{
		// tok.val = str up to a non-literal char
		len = 0;
		while (str[len + *i] && identify_tok(str[len + *i]) == I_LITERAL)
			len++;
		tok->val = malloc(sizeof(char) * (len + 2));
		if (!tok->val)
			return (NULL);
		len = 0;
		while (str[len + *i] && identify_tok(str[len + *i]) == I_LITERAL)
		{
			tok->val[len] = str[len + *i];
			len++;
		}
		tok->val[len] = '\0';
		*i += len;
	}
	else if (tok->type == I_SPACE)
	{
		tok->val = ft_strdup(" ");
		*i += 1;
	}
	else if (tok->type == I_OUTREDIR)
	{
		if (str[*i + 1] == '>')
			tok->val = ft_strdup(">>");
		else
			tok->val = ft_strdup(">");
		*i += ft_strlen(tok->val);
	}
	else if (tok->type == I_INREDIR)
	{
		if (str[*i + 1] == '<')
			tok->val = ft_strdup("<<");
		else
			tok->val = ft_strdup("<");
		*i += ft_strlen(tok->val);
	}
	else if (tok->type == I_PIPE)
	{
		tok->val = ft_strdup("|");
		*i += 1;
	}
	else if (tok->type == I_S_QUOTE || tok->type == I_D_QUOTE)
	{
		// tok.val = str up to SQ or DQ (w/o quotes)
		len = 0;
		while (str[len + *i] && identify_tok(str[len + *i]) != tok->type)
			len++;
		tok->val = malloc(sizeof(char) * (len + *i));
		if (!tok->val)
			return (NULL);
		len = 1;	// to skip first char (that is a quote)
		while (str[len + *i] && identify_tok(str[len + *i]) != tok->type)
		{
			tok->val[len - 1] = str[len + *i];
			len++;
		}
		tok->val[len - 1] = '\0';
		*i += len + 1;
	}
	/////////////////////////////////////////
	ft_printf("tok->val = %s\n", tok->val);
	/////////////////////////////////////////
	return (tok);
}
