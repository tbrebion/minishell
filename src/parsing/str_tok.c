/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/05/16 18:21:11 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	**str_tok(char *str)
{
	t_list	**Tokens;
	int		i;

	// Tokens = NULL;
	Tokens = malloc(sizeof(t_list *));
	if (!Tokens)
		return (NULL);
	*Tokens = NULL;
	i = 0;
	while (str[i])
	{
		ft_printf("i = %d\n", i);
		ft_lstadd_back(Tokens, ft_lstnew((t_tok *)set_tok(str, &i)));
	}
	return (Tokens);
}

int	main(int ac, char **av)
{
	t_list	**Tokens;
	t_list	*lst;
	t_list	*prev;

	(void)ac;
	Tokens = str_tok(av[1]);
	lst = *Tokens;
	while (lst)
	{
	/////////////////////////////////////////
		ft_printf("tok.type = %d\ttok.val = %s\n", lst->content->type, lst->content->val);
	/////////////////////////////////////////
		prev = lst;
		lst = lst->next;
		free(prev->content->val);
		free(prev);
	}
	return (0);
}
