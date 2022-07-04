/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_to_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:57:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
static void debug(char **cli)
{
	int	i = -1;

	while (cli[++i])
	{
		ft_printf("%d : %s\n", i, cli[i]);
	}
	i++;
	// ft_printf("%d : %s\n", i, cli[i]);
}

char	**tok_to_cli(t_list **tokens, int tok_nb)
{
	char	**cli;
	t_list	*lst;
	int		i;

	cli = malloc(sizeof(char *) * (tok_nb));
	lst = *tokens;
	i = 0;
	while (lst && i < tok_nb)
	{
		cli[i] = ft_strdup("");
		while (lst && lst->content->type >= I_OUTREDIR && \
			lst->content->type <= I_PIPE)
		{
			if (cli[i][0])
				cli[i] = ft_strjoin(cli[i], " ");
			cli[i] = ft_strjoin(cli[i], lst->content->val);
			lst = lst->next;
		}
		if (lst)
			lst = lst->next;
		i++;
	}
	return (cli);
}
*/
