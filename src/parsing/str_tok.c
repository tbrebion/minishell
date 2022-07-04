/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 14:00:14 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	**str_tok(char *str)
{
	t_list	**tokens;
	int		i;

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
	data.tok_nb = ft_lstsize(*tokens);
	return (tokens);
}
