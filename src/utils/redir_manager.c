/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:25 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redir_first(void)
{
	if ((get_n_lst(g_data.tokens, 0)->content->type) == I_OUTREDIR)
		return (1);
	if ((get_n_lst(g_data.tokens, 0)->content->type) == I_D_OUTREDIR)
		return (2);
	if ((get_n_lst(g_data.tokens, 0)->content->type) == I_INREDIR)
		return (3);
	if ((get_n_lst(g_data.tokens, 0)->content->type) == I_D_INREDIR)
		return (4);
	return (-1);
}

void	redir_manager(void)
{
	t_list	*lst;

	lst = (*g_data.tokens);
	while (lst)
	{
		if (lst->next && (lst->content->type == I_OUTREDIR \
			&& (lst->next->content->type < I_OUTREDIR \
			|| lst->content->type > I_PIPE)))
			redir_out(lst->next->content->val);
		if (lst->next && (lst->content->type == I_D_OUTREDIR \
			&& (lst->next->content->type < I_OUTREDIR \
			|| lst->content->type > I_PIPE)))
			redir_out_append(lst->next->content->val);
		if (lst->next && (lst->content->type == I_INREDIR \
			&& (lst->next->content->type < I_OUTREDIR \
			|| lst->content->type > I_PIPE)))
			redir_in(lst->next->content->val);
		if (lst->content->type == I_D_INREDIR)
			here_doc();
		lst = lst->next;
	}
}
