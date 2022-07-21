/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/21 16:11:23 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*limiter_handler(char *str);
// static char	*limiter_in_quotes(char *str, int i, int j);

t_list	**str_tok(char *str)
{
	t_list	**tokens;
	int		i;

	// if (g_data.limiter)
	// 	free(g_data.limiter);
	g_data.limiter = limiter_handler(str);
	tokens = malloc(sizeof(t_list *));
	if (!tokens)
		return (NULL);
	*tokens = NULL;
	i = 0;
	while (str[i])
	{
		if (identify_tok(str[i]) != I_SPACE)
			ft_lstadd_back(tokens, ft_lstnew((t_tok *)set_tok(str, &i)));
		else
			i++;
	}
	g_data.tok_nb = ft_lstsize(*tokens);
	return (tokens);
}

static char	*limiter_handler(char *str)
{
	int		i;
	int		j;
	char	*lim;

	i = 0;
	j = 0;
	lim = malloc(4096);
	lim[0] = '\0';
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			i += 2;
			while (str[i] == ' ')
				i++;
			// lim = limiter_in_quotes(str, i, j);
			// if (lim)
				// break ;
			while (str[i] && str[i] != ' ')
				lim[j++] = str[i++];
			lim[j] = '\0';
			break ;
		}
		i++;
	}
	if (!lim[0])
	{
		free(lim);
		return (NULL);
	}
	return (lim);
}

// static char	*limiter_in_quotes(char *str, int i, int j)
// {
// 	char *lim;

// 	lim = NULL;
// 	if (str[i] != '\"' || str[i] != '\'')
// 		return (NULL);
// 	if (str[i] == '\"')	
// 	{
// 		i++;
// 		while (str[i] != '\"')
// 			lim[j++] = str[i++];
// 		lim[j] = '\0';
// 		return (lim);
// 	}
// 	if (str[i] == '\'')	
// 	{
// 		i++;
// 		while (str[i] != '\'')
// 			lim[j++] = str[i++];
// 		lim[j] = '\0';
// 		return (lim);
// 	}
// 	return (lim);
// }
