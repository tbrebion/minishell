/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:57:23 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
