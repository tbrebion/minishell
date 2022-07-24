/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/24 12:38:12 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	rotate_tokens(void)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	int		prev_type;
	char	*concat;
	t_list	**new;

	if (redir_first() != -1)
	{
		/*
		PLACER LE PREMIER TOKEN LITERAL (NON PRECEDE DUN TOKEN REDIR)
		EN PREMIER DANS LA LISTE
		*/
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
	////////////////////////////////////////////////////////
	// lst = (*g_data.tokens);
	// ft_printf("\n");
	// while (lst)
	// {
	// 	ft_printf("%s[%s]%s[%d]%s","\x1B[31m", lst->content->val, "\x1B[34m", lst->content->type, "\x1B[0m");
	// 	lst = lst->next;
	// }
	// ft_printf("\n\n");
	////////////////////////////////////////////////////////
	/*
	CHANGER LA VAL DU PREMIER TOKEN DE LA LISTE PAR LA CONCATENATION
	DE TOUS LES TOKENS LITERAUX (NON PRECEDES DUN TOKEN REDIR)
	*/
	/////////////////////////////
	// ft_printf("%s\n\n", (*g_data.tokens)->content->val);
	/////////////////////////////
	concat = ft_strdup((*g_data.tokens)->content->val);
	concat = ft_strjoin(concat, " ");
	lst = (*g_data.tokens)->next;
	i = 1;
	while (lst)
	{
		///////////////////////////////
		// ft_printf("%s[%s]%s[%d]%s","\x1B[31m", lst->content->val, "\x1B[34m", lst->content->type, "\x1B[0m");
		///////////////////////////////
		if (lst->content->type == I_LITERAL \
			|| lst->content->type == I_S_QUOTE \
			|| lst->content->type == I_D_QUOTE)
		{
			prev_type = get_n_lst(g_data.tokens, i - 1)->content->type;
			if (!(prev_type >= I_OUTREDIR && prev_type <= I_D_INREDIR))
			{
				concat = ft_strjoin(concat, lst->content->val);
				concat = ft_strjoin(concat, " ");
				get_n_lst(g_data.tokens, i - 1)->next = lst->next;
				i--;
			}
		}
		lst = lst->next;
		i++;
	}
	/*
	TRAMSFORMER CONCAT EN UNE NOUVELLE LISTE DE TOKENS
	PLACER CETTE LISTE EN DEBUT DE LANCIENNE APRES AVOIR SUPPRIMER LE PREMIER TOKEN DE LANCIENNE
	*/
	new = str_tok(concat);
	tmp = (*g_data.tokens)->next;
	free((*g_data.tokens)->content->val);
	free((*g_data.tokens)->content);
	free(*g_data.tokens);
	g_data.tokens = new;
	lst = *g_data.tokens;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	////////////////////////////////////////////////////////
	// lst = (*g_data.tokens);
	// ft_printf("\n");
	// while (lst)
	// {
	// 	ft_printf("%s[%s]%s","\x1B[31m", lst->content->val, "\x1B[0m");
	// 	lst = lst->next;
	// }
	// ft_printf("\n\n");
	////////////////////////////////////////////////////////
}

// void	rotate_tokens(void)
// {
// 	t_list	*tmp;
// 	t_list	*save;
// 	int		i;

// 	if (redir_first() == -1)
// 		return ;
// 	i = 0;
// 	while (i++ < g_data.tok_nb - 2)
// 	{
// 		if (!(*g_data.tokens) || ft_lstsize(*g_data.tokens) < 2)
// 			return ;
// 		save = (*g_data.tokens);
// 		while ((*g_data.tokens)->next->next != NULL)
// 			(*g_data.tokens) = (**g_data.tokens).next;
// 		tmp = (*g_data.tokens)->next;
// 		(*g_data.tokens)->next = NULL;
// 		(*g_data.tokens) = tmp;
// 		(*g_data.tokens)->next = save;
// 	}
// 	g_data.lst = (*g_data.tokens);
// }

int	redir_first(void)
{
	if((get_n_lst(g_data.tokens, 0)->content->type) == I_OUTREDIR)
		return (1);
	if((get_n_lst(g_data.tokens, 0)->content->type) == I_D_OUTREDIR)
		return (2);
	if((get_n_lst(g_data.tokens, 0)->content->type) == I_INREDIR)
		return (3);
	if((get_n_lst(g_data.tokens, 0)->content->type) == I_D_INREDIR)
		return (4);
	return (-1);
}

void	redir_manager(void)
{
	t_list	*lst;

	lst = (*g_data.tokens);
	while (lst)
	{
		if (lst->content->type == I_OUTREDIR)
			redir_out(lst->next->content->val);
		if (lst->content->type == I_D_OUTREDIR)
			redir_out_append(lst->next->content->val);
		if (lst->content->type == I_INREDIR)
			redir_in(lst->next->content->val);
		if (lst->content->type == I_D_INREDIR)
			here_doc();
		lst = lst->next;
	}
}
