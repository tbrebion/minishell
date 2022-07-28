/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:16:16 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/28 17:24:09 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	replace_first(void);
static char	*set_concat(void);
static void	set_concat_supply(char *concat, t_list *lst, t_list *tmp, int *i, \
int prev_type);
static void	new_list(char *concat);

int	rotate_tokens(void)
{
	char	*concat;

	if (is_multi_redir() == 0)
	{
		rotate_tokens_bis();
		return (0);
	}
	if (redir_first() != -1)
		replace_first();
	concat = set_concat();
	if (!concat)
		return (1);
	new_list(concat);
	return (0);
}

/*
PLACER LE PREMIER TOKEN LITERAL (NON PRECEDE DUN TOKEN REDIR)
EN PREMIER DANS LA LISTE
*/
static void	replace_first(void)
{
	int		i;
	int		prev_type;
	t_list	*lst;

	lst = (*g_data.tokens)->next;
	i = 1;
	while (lst)
	{
		if (lst->content->type == I_LITERAL \
			|| lst->content->type == I_S_QUOTE \
			|| lst->content->type == I_D_QUOTE)
		{
			prev_type = get_n_lst(g_data.tokens, i - 1)->content->type;
			if (!(prev_type >= I_OUTREDIR && prev_type <= I_D_INREDIR))
			{
				get_n_lst(g_data.tokens, i - 1)->next = lst->next;
				lst->next = *g_data.tokens;
				*g_data.tokens = lst;
				break ;
			}
		}
		i++;
		lst = lst->next;
	}
}

/*
CHANGER LA VAL DU PREMIER TOKEN DE LA LISTE PAR LA CONCATENATION
DE TOUS LES TOKENS LITERAUX (NON PRECEDES DUN TOKEN REDIR)
*/
static char	*set_concat(void)
{
	char	*concat;
	t_list	*lst;
	t_list	*tmp;
	int		i;
	int		prev_type;

	tmp = NULL;
	prev_type = 0;
	if (is_space((*g_data.tokens)->content->val))
	{
		ft_putstr_fd((*g_data.tokens)->content->val, 0);
		ft_putstr_fd(" : command not found\n", 0);
		free_loop();
		return (NULL);
	}
	concat = ft_strdup((*g_data.tokens)->content->val);
	concat = ft_strjoin(concat, " ");
	lst = (*g_data.tokens)->next;
	i = 1;
	while (lst)
		set_concat_supply(concat, lst, tmp, &i, prev_type);
	return (concat);
}

static void	set_concat_supply(char *concat, t_list *lst, t_list *tmp, int *i, \
int prev_type)
{
	tmp = lst->next;
	if (lst->content->type == I_LITERAL || lst->content->type == I_S_QUOTE \
		|| lst->content->type == I_D_QUOTE)
	{
		prev_type = get_n_lst(g_data.tokens, *i - 1)->content->type;
		if (!(prev_type >= I_OUTREDIR && prev_type <= I_D_INREDIR))
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
			get_n_lst(g_data.tokens, (*i)-- - 1)->next = lst->next;
			free(lst->content->val);
			free(lst->content);
			free(lst);
		}
	}
	lst = tmp;
	(*i)++;
}

/*
TRAMSFORMER CONCAT EN UNE NOUVELLE LISTE DE TOKENS
PLACER CETTE LISTE EN DEBUT DE LANCIENNE
APRES AVOIR SUPPRIMER LE PREMIER TOKEN DE LANCIENNE
*/
static void	new_list(char *concat)
{
	t_list	**new;
	t_list	*lst;
	t_list	*tmp;

	new = str_tok(concat);
	free(concat);
	tmp = (*g_data.tokens)->next;
	free((*g_data.tokens)->content->val);
	free((*g_data.tokens)->content);
	free(*g_data.tokens);
	free(g_data.tokens);
	g_data.tokens = new;
	lst = *g_data.tokens;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
}
