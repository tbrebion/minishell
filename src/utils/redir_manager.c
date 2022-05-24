/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/24 14:00:17 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redir_manager(t_data *data)
{
	t_list	*lst;

	lst = (*data->Tokens);
	while (lst)
	{
		if (lst->content->type == I_OUTREDIR)
			redir_out(lst->next->content->val);
		lst = lst->next;
	}
}
