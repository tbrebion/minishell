/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:56:43 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:31 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	tok_index(t_tok *find)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = *g_data.tokens;
	while (lst)
	{
		if (lst->content == find)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}
