/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:56:57 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:57:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_tokens(t_list **tokens);
// static void	free_cli(void);

void	free_loop(void)
{
	if (g_data.tokens)
		free_tokens(g_data.tokens);
	if (g_data.input)
		free(g_data.input);
}

static void	free_tokens(t_list **tokens)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *tokens;
	while (lst)
	{
		tmp = lst->next;
		free(lst->content->val);
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	free(tokens);
}
/*
static void	free_cli(void)
{
	int	i;

	i = 0;
	while (g_data.cli[i])
	{
		free(g_data.cli[i]);
		i++;
	}
	free(g_data.cli);
}
*/
