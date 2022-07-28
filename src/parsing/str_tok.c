/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/28 16:31:55 by tbrebion         ###   ########.fr       */
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
	g_data.tok_nb = ft_lstsize(*tokens);
	return (tokens);
}

char	**limiter_handler(void)
{
	t_list	*lst;
	char	**limiters;
	int		i;

	lst = (*g_data.tokens);
	if (nb_here_doc() < 1)
		return (NULL);
	limiters = malloc(sizeof(char *) * (nb_here_doc() + 1));
	limiters[nb_here_doc()] = NULL;
	if (nb_here_doc() == g_data.tok_nb \
		|| nb_here_doc() > g_data.tok_nb / 2)
	{
		free(limiters);
		limiters = NULL;
		return (NULL);
	}
	i = 0;
	while (lst)
	{
		if (lst->content->type == I_D_INREDIR && \
		lst->next && lst->next->content->type != I_D_INREDIR)
			limiters[i++] = ft_strdup(lst->next->content->val);
		lst = lst->next;
	}
	return (limiters);
}
