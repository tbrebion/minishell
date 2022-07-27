/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/27 17:29:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	rotate_tokens_bis(void);

int	rotate_tokens(void)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;
	int		prev_type;
	char	*concat;
	t_list	**new;

	if (is_multi_redir() == 0)
	{
		rotate_tokens_bis();
		return (0);
	}
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
	if (is_space((*g_data.tokens)->content->val))
	{
		ft_putstr_fd((*g_data.tokens)->content->val, 0);
		ft_putstr_fd(" : command not found\n", 0);
		return (1);
	}
	concat = ft_strdup((*g_data.tokens)->content->val);
	concat = ft_strjoin(concat, " ");
	lst = (*g_data.tokens)->next;
	i = 1;
	while (lst)
	{
		///////////////////////////////
		// ft_printf("%s[%s]%s[%d]%s","\x1B[31m", lst->content->val, "\x1B[34m", lst->content->type, "\x1B[0m");
		///////////////////////////////
		tmp = lst->next;
		if (lst->content->type == I_LITERAL \
			|| lst->content->type == I_S_QUOTE \
			|| lst->content->type == I_D_QUOTE)
		{
			prev_type = get_n_lst(g_data.tokens, i - 1)->content->type;
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
				get_n_lst(g_data.tokens, i - 1)->next = lst->next;
				free(lst->content->val);
				free(lst->content);
				free(lst);
				i--;
			}
		}
		lst = tmp;
		i++;
	}
	/*
	TRAMSFORMER CONCAT EN UNE NOUVELLE LISTE DE TOKENS
	PLACER CETTE LISTE EN DEBUT DE LANCIENNE APRES AVOIR SUPPRIMER LE PREMIER TOKEN DE LANCIENNE
	*/
	new = str_tok(concat);
	free(concat);
	tmp = (*g_data.tokens)->next;
	// free(get_n_lst(g_data.tokens, 0)->content->val);
	// free(get_n_lst(g_data.tokens, 0)->content);
	// free(get_n_lst(g_data.tokens, 0));
	free((*g_data.tokens)->content->val);
	free((*g_data.tokens)->content);
	free(*g_data.tokens);
	free(g_data.tokens);
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
	return (0);
}

static void	rotate_tokens_bis(void)
{
	t_list	*tmp;
	t_list	*save;
	int		i;

	if (redir_first() == -1)
		return ;
	i = 0;
	while (i++ < g_data.tok_nb - 2)
	{
		if (!(*g_data.tokens) || ft_lstsize(*g_data.tokens) < 2)
			return ;
		save = (*g_data.tokens);
		while ((*g_data.tokens)->next->next != NULL)
			(*g_data.tokens) = (**g_data.tokens).next;
		tmp = (*g_data.tokens)->next;
		(*g_data.tokens)->next = NULL;
		(*g_data.tokens) = tmp;
		(*g_data.tokens)->next = save;
	}
	g_data.lst = (*g_data.tokens);
}

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
		if (lst->next  && (lst->content->type == I_OUTREDIR \
			&& (lst->next->content->type < I_OUTREDIR \
			|| lst->content->type > I_PIPE)))
			redir_out(lst->next->content->val);
		if (lst->next  && (lst->content->type == I_D_OUTREDIR \
			&& (lst->next->content->type < I_OUTREDIR \
			|| lst->content->type > I_PIPE)))
			redir_out_append(lst->next->content->val);
		if (lst->next  && (lst->content->type == I_INREDIR \
			&& (lst->next->content->type < I_OUTREDIR \
			|| lst->content->type > I_PIPE)))
			redir_in(lst->next->content->val);
		if (lst->content->type == I_D_INREDIR)
			here_doc();
		lst = lst->next;
	}
}
