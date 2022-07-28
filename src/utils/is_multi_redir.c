/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_multi_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:31:45 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/28 15:54:53 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_multi_redir(void)
{
	t_list	*lst;
	int		redir_nb;

	lst = (*g_data.tokens);
	redir_nb = 0;
	while (lst)
	{
		if (lst->content->type == I_OUTREDIR \
			|| lst->content->type == I_INREDIR \
			|| lst->content->type == I_D_OUTREDIR \
			|| lst->content->type == I_D_INREDIR)
			redir_nb++;
		lst = lst->next;
	}
	return (redir_nb);
}
