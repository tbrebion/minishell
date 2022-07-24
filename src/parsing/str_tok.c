/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/22 19:10:52 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*limiter_handler(char *str);
static int	limiter_in_quotes(char *str, char *lim, int i, int j);
// static int	backslash_limiter(char *str, char *lim, int i, int j);

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

char	*limiter_handler(char *str)
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
			if (limiter_in_quotes(str, lim, i, j) == 1)
				break ;
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

static int	limiter_in_quotes(char *str, char *lim, int i, int j)
{
	if (str[i] != '\"' && str[i] != '\'')
		return (0);
	if (str[i] == '\"')	
	{
		i++;
		while (str[i] != '\"')
			lim[j++] = str[i++];
		j--;
		lim[j] = '\0';
	}
	if (str[i] == '\'')	
	{
		i++;
		while (str[i] != '\'')
			lim[j++] = str[i++];
		j--;
		lim[j] = '\0';
	}
	return (1);
}

// static	int backslash_limiter(char *str, char *lim, int i, int j)
// {
// 	if (str[i] == '\\' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
// 	{
// 		lim[j] = '\0';
// 		return (1);
// 	}
// 	else if (str[i] == '\\' && str[i + 1] != ' ' && str[i + 1] != '\0')
// 		return (2);
// 	return (0);
// }
