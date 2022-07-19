/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/19 18:54:54 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	rotate_tokens(void)
{
	t_list	*tmp;
	t_list	*save;
	// t_list	*tmp_dos;
	// t_list	*save_dos;

	if (redir_first() == -1)
		return ;
	if (!(*g_data.tokens) || ft_lstsize(*g_data.tokens) < 2)
		return ;
	save = (*g_data.tokens);
	while ((*g_data.tokens)->next->next != NULL)
		(*g_data.tokens) = (**g_data.tokens).next;
	tmp = (*g_data.tokens)->next;
	(*g_data.tokens)->next = NULL;
	(*g_data.tokens) = tmp;
	(*g_data.tokens)->next = save;

	// save_dos = (g_data.lst);
	// while ((g_data.lst)->next->next != NULL)
	// 	(g_data.lst) = (*g_data.lst).next;
	// tmp_dos = (g_data.lst)->next;
	// (g_data.lst)->next = NULL;
	// (g_data.lst) = tmp_dos;
	// (g_data.lst)->next = save_dos;
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
