/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_tok.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:45:18 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:57:23 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	remove_space_tok(t_list **tokens)
// {
// 	t_list	*lst;
// 	t_list	*prev;
// 	t_list	*tmp;

// 	lst = *tokens;
// 	prev = NULL;
// 	while (lst)
// 	{
// 		tmp = lst->next;
// 		prev = lst;
// 		if (lst->content->type == I_SPACE)
// 		{
// 			free(lst->content->val);
// 			if (lst == *tokens)
// 			{
// 				*tokens = lst->next;
// 			}
// 			free(lst);
// 		}
// 		lst = lst->next;
// 	}
// }
