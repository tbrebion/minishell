/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:54:47 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:12 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*get_n_lst(t_list **tokens, int n)
{
	t_list	*lst;

	lst = *tokens;
	while (lst && n)
	{
		lst = lst->next;
		n--;
	}
	return (lst);
}
