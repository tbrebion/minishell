/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:16:16 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/30 07:50:48 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	if_redir_first(void);
static void	new_list(char *concat);

int	rotate_tokens(void)
{
	char	*concat;

	if (is_multi_redir() == 0)
	{
		rotate_tokens_bis();
		return (0);
	}
	if_redir_first();
	if (is_space((*g_data.tokens)->content->val))
	{
		ft_putstr_fd((*g_data.tokens)->content->val, 0);
		ft_putstr_fd(" : command not found\n", 0);
		free_loop();
		return (1);
	}
	concat = concat_tokens();
	new_list(concat);
	return (0);
}

/*
PLACER LE PREMIER TOKEN LITERAL (NON PRECEDE DUN TOKEN REDIR)
EN PREMIER DANS LA LISTE
*/
static void	if_redir_first(void)
{
	t_list	*lst;
	int		i;
	int		prev_type;

	if (redir_first() != -1)
	{
		lst = (*g_data.tokens)->next;
		i = 1;
		while (lst)
		{
			if (is_lit_or_quotes(lst->content))
			{
				prev_type = get_n_lst(g_data.tokens, i - 1)->content->type;
				if (!(prev_type >= I_OUTREDIR && prev_type <= I_D_INREDIR))
				{
					get_n_lst(g_data.tokens, i - 1)->next = lst->next;
					lst->next = *g_data.tokens;
					*g_data.tokens = lst;
					break ;
				}
			}
			i++;
			lst = lst->next;
		}
	}
}

/*
TRAMSFORMER CONCAT EN UNE NOUVELLE LISTE DE TOKENS
PLACER CETTE LISTE EN DEBUT DE LANCIENNE APRES AVOIR SUPPRIMER LE PREMIER
TOKEN DE LANCIENNE
*/
static void	new_list(char *concat)
{
	t_list	**new;
	t_list	*lst;
	t_list	*tmp;

	new = str_tok(concat);
	free(concat);
	tmp = (*g_data.tokens)->next;
	free((*g_data.tokens)->content->val);
	free((*g_data.tokens)->content);
	free(*g_data.tokens);
	free(g_data.tokens);
	g_data.tokens = new;
	lst = *g_data.tokens;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
}
