/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_to_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/06 15:43:35 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
static void debug(char **Cli)
{
	int	i = -1;

	while (Cli[++i])
	{
		ft_printf("%d : %s\n", i, Cli[i]);
	}
	i++;
	// ft_printf("%d : %s\n", i, Cli[i]);
}
*/
char	**tok_to_cli(t_list **Tokens, int tok_nb)
{
	char	**Cli;
	t_list	*lst;
	int		i;

	Cli = malloc(sizeof(char *) * (tok_nb));
	lst = *Tokens;
	i = 0;
	while (lst && i < tok_nb)
	{
		Cli[i] = ft_strdup("");
		while (lst && lst->content->type >= I_OUTREDIR && \
			lst->content->type <= I_PIPE)
		{
			if (Cli[i][0])
				Cli[i] = ft_strjoin(Cli[i], " ");
			Cli[i] = ft_strjoin(Cli[i], lst->content->val);
			lst = lst->next;
		}
		if (lst)
			lst = lst->next;
		i++;
	}
	//debug(Cli);
	return (Cli);
}
