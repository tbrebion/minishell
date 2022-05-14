/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:45:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/14 02:53:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int		identify_tok(char c);
static int		count_tok(char *str);
static t_tok	*set_tok(char *str, int *i);
static void		set_tok_single_char(t_tok *tok);

// str_tok will return a t_tok array, ending with a t_tok.val = NULL so that it can be travelled
t_list	**str_tok(char *str)
{
	t_list	**Tok;
	int		tok_nb;
	int		i;
	int		j;

	tok_nb = count_tok(str);
	Tok = NULL;
	ft_printf("tok_nb = %d\n", tok_nb);
	i = 0;
	j = 0;
	while (i < tok_nb)
	{
		ft_lstadd_back(Tok, ft_lstnew(set_tok(str, &i)));
		i++;
	}
	// DEBUG
	int u = 0;
	t_list	*lst = *Tok;
	while (u < tok_nb)
	{
		ft_printf("u = %d\n", u);
		ft_printf("Tok[%d].val = %s\tTok[%d].type = %d\n", u, lst->tok->type, u, lst->tok->type);
		lst = lst->next;
		u++;
	}
	// END_DEBUG
	return (Tok);
}

int	main(int ac, char **av)
{
	(void)ac;
	ft_printf("int size = %d\tchar size = %d\n", sizeof(int), sizeof(char));
	str_tok(av[1]);
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

static int	count_tok(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		// ft_printf("[identify_tok] : %d\n", identify_tok(str[i]));
		// check if it's a single or double (> || >>)
		if (identify_tok(str[i]) == I_OUTREDIR)
		{
			if (str[i + 1] && identify_tok(str[i + 1]) == I_OUTREDIR)
				i++;
			i++;
		}
		// check if it's a single or double (< || <<)
		else if (identify_tok(str[i]) == I_INREDIR)
		{
			if (str[i + 1] && identify_tok(str[i + 1]) == I_INREDIR)
				i++;
			i++;
		}
		// go to end of I_LITERAL token
		else if (identify_tok(str[i]) == I_LITERAL)
			while (str[i] && identify_tok(str[i]) == I_LITERAL)
				i++;
		else
			i++;
		res++;
	}
	return (res);
}

static t_tok	*set_tok(char *str, int *i)
{
	t_tok	*tok;

	tok = malloc(sizeof(tok));
	if (!tok)
		return (NULL);
	ft_printf("i = %d str[i] = %c\n", *i, str[*i]);
	tok->type = identify_tok(str[*i]);
	ft_printf("tok.type = %d\n", tok->type);
	if (tok->type == I_OUTREDIR)
	{
		tok->val = ">";
		if (str[*i + 1] && identify_tok(str[*i + 1]) == I_OUTREDIR)
		{
			tok->val = ">>";
			(*i)++;
		}
		(*i)++;
	}
	else if (tok->type == I_INREDIR)
	{
		tok->val = "<";
		if (str[*i + 1] && identify_tok(str[*i + 1]) == I_INREDIR)
		{
			tok->val = "<<";
			(*i)++;
		}
		(*i)++;
	}
	else if (tok->type == I_SPACE || tok->type == I_PIPE || \
		tok->type == I_S_QUOTE || tok->type == I_D_QUOTE)
		{
			set_tok_single_char(tok);
			(*i)++;
		}
	else if (tok->type == I_LITERAL)
	{
		tok->val = ft_strdup("");
		while (str[*i] && identify_tok(str[*i]) == I_LITERAL)
		{
			tok->val = stradd_char(tok->val, str[*i]);
			(*i)++;
		}
	}
	ft_printf("tok.val = \"%s\"\n", tok->val);
	return (tok);
}

static void	set_tok_single_char(t_tok *tok)
{
	if (tok->type == I_SPACE)
		tok->val = " ";
	else if (tok->type == I_PIPE)
		tok->val = "|";
	else if (tok->type == I_S_QUOTE)
		tok->val = "\'";
	else if (tok->type == I_D_QUOTE)
		tok->val = "\"";
}
