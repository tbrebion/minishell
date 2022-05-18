/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_to_cli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/18 14:13:55 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		while (lst && lst->content->type != I_PIPE)
		{
			if (Cli[i][0])
				Cli[i] = ft_strjoin(Cli[i], " ");
			Cli[i] = ft_strjoin(Cli[i], lst->content->val);
			lst = lst->next;
		}
		i++;
	}
	return (Cli);
}
