/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/20 15:13:29 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*limiter_handler(char *str);

t_list	**str_tok(char *str)
{
	t_list	**tokens;
	int		i;

	if (g_data.limiter)
		free(g_data.limiter);
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
			while (str[i] && str[i] != ' ')
				lim[j++] = str[i++];
			lim[j] = '\0';
			break ;
		}
		i++;
	}
	if (!lim[0])
		return (NULL);
	return (lim);
}
