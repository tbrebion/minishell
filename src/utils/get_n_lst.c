/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:54:47 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/18 12:03:40 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*get_n_lst(t_list **Tokens, int n)
{
	t_list	*lst;

	lst = *Tokens;
	while (lst && n)
	{
		lst = lst->next;
		n--;
	}
	// ft_printf("[get_n_lst] n = %d\ttok.val = %s\ttok.type = %d\n", n, lst->content->val, lst->content->type);
	return (lst);
}
