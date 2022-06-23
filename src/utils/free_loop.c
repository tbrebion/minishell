/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:56:57 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/23 11:52:01 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_tokens(t_list **Tokens);
// static void	free_cli(void);

void	free_loop(void)
{
	if (data.Tokens)
		free_tokens(data.Tokens);
	if (data.input)
		free(data.input);
	if (data.all_cmd)
		free_split(data.all_cmd);
	/*if (data.Cli && data.Cli[0][0])
		free_cli();*/
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
	while (data.Cli[i])
	{
		free(data.Cli[i]);
		i++;
	}
	free(data.Cli);
}
*/