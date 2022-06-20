/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:51:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/06/20 14:31:15 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	**str_tok(char *str/*, t_data *data*/)
{
	t_list	**Tokens;
	// t_tok	*tmp;
	int		i;

	Tokens = malloc(sizeof(t_list *));
	if (!Tokens)
		return (NULL);
	*Tokens = NULL;
	i = 0;
	while (str[i])
	{
		// tmp = set_tok(str, &i);
		if (identify_tok(str[i]) != I_SPACE)
			ft_lstadd_back(Tokens, ft_lstnew((t_tok *)set_tok(str, &i)/*tmp*/)); ////////////////////////////////// le retour de set_tok peut pas etre free 
		else
			i++;
	}
	data.tok_nb = ft_lstsize(*Tokens);
	return (Tokens);
}

// int	main(int ac, char **av)
// {
// 	t_list	**Tokens;
// 	t_list	*lst;
// 	t_list	*prev;

// 	(void)ac;
// 	Tokens = str_tok(av[1]);
// 	lst = *Tokens;
// 	while (lst)
// 	{
// 	/////////////////////////////////////////
// 		ft_printf("tok.type = %d\ttok.val = %s\n", lst->content->type, lst->content->val);
// 	/////////////////////////////////////////
// 		prev = lst;
// 		lst = lst->next;
// 		free(prev->content->val);
// 		free(prev);
// 	}
// 	return (0);
// }
