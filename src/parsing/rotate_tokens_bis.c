/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tokens_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:15:28 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/30 07:50:47 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	rotate_tokens_bis(void)
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
