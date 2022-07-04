/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:56:57 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_tokens(t_list **Tokens);
// static void	free_cli(void);

void	free_loop(void)
{
	if (g_data.Tokens)
		free_tokens(g_data.Tokens);
	if (g_data.input)
		free(g_data.input);
}

static void	free_tokens(t_list **Tokens)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *Tokens;
	while (lst)
	{
		tmp = lst->next;
		free(lst->content->val);
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	free(Tokens);
}
/*
static void	free_cli(void)
{
	int	i;

	i = 0;
	while (g_data.Cli[i])
	{
		free(g_data.Cli[i]);
		i++;
	}
	free(g_data.Cli);
}
*/
