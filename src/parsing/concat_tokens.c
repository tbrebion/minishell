/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:33:05 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/29 14:36:22 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*concat_tokens_supply(char *concat, t_list *lst);
static char	*concat_tokens_supply_encore(char *concat, int *i, t_list *lst);

/*
CONCATENER LA VALEUR DE TOUS LES TOKENS ARGUMENTS DE LA COMMANDE
ET SUPPRIMER CES TOKENS DE LA LISTE
*/
char	*concat_tokens(void)
{
	char	*concat;
	int		prev_type;
	int		i;
	t_list	*lst;
	t_list	*tmp;

	concat = ft_strdup((*g_data.tokens)->content->val);
	concat = ft_strjoin(concat, " ");
	lst = (*g_data.tokens)->next;
	i = 1;
	while (lst)
	{
		tmp = lst->next;
		if (is_lit_or_quotes(lst->content))
		{
			prev_type = get_n_lst(g_data.tokens, i - 1)->content->type;
			if (!(prev_type >= I_OUTREDIR && prev_type <= I_D_INREDIR))
				concat = concat_tokens_supply_encore(concat, &i, lst);
		}
		lst = tmp;
		i++;
	}
	return (concat);
}

static char	*concat_tokens_supply(char *concat, t_list *lst)
{
	if (lst->content->type == I_S_QUOTE)
		concat = ft_strjoin(concat, "\'");
	else if (lst->content->type == I_D_QUOTE)
		concat = ft_strjoin(concat, "\"");
	concat = ft_strjoin(concat, lst->content->val);
	if (lst->content->type == I_S_QUOTE)
		concat = ft_strjoin(concat, "\'");
	else if (lst->content->type == I_D_QUOTE)
		concat = ft_strjoin(concat, "\"");
	concat = ft_strjoin(concat, " ");
	return (concat);
}

static char	*concat_tokens_supply_encore(char *concat, int *i, t_list *lst)
{
	concat = concat_tokens_supply(concat, lst);
	get_n_lst(g_data.tokens, (*i) - 1)->next = lst->next;
	(*i)--;
	free_node(lst);
	return (concat);
}
