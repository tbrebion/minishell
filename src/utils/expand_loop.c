/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:32:39 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:00 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	expand_loop(void)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = *g_data.tokens;
	while (lst)
	{
		if (lst && get_n_lst(g_data.tokens, i - 1) \
			&& get_n_lst(g_data.tokens, i - 1)->content->type != I_D_INREDIR \
			&& (lst->content->type == I_LITERAL \
			|| lst->content->type == I_D_QUOTE))
			lst->content->val = expand_str(lst->content->val);
		lst = lst->next;
		i++;
	}
}
