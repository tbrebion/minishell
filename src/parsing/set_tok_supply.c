/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tok_supply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:02:53 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/30 07:50:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_simple(char *str, int *i, t_tok *tok)
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

void	set_lit(char *str, int *i, t_tok *tok)
{
	int	len;

	if (tok->type == I_LITERAL)
	{
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

void	set_quotes(char *str, int *i, t_tok *tok)
{
	int	len;

	len = 0;
	while (str[len + *i + 1] && identify_tok(str[len + *i + 1]) != tok->type)
		len++;
	tok->val = malloc(sizeof(char) * (len + *i) + 1);
	if (!tok->val)
		return ;
	len = 1;
	while (str[len + *i] && identify_tok(str[len + *i]) != tok->type)
	{
		tok->val[len - 1] = str[len + *i];
		len++;
	}
	tok->val[len - 1] = '\0';
	*i += len + 1;
}

void	set_redir(char *str, int *i, t_tok *tok)
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

// void	set_q_to_l(t_tok *tok)
// {
// 	if (tok->type != I_S_QUOTE)
// 		tok->val = expand_str(tok->val);
// }
