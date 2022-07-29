/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:41:41 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/29 12:33:07 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_meta_char(void)
{
	while (g_data.lst->next)
	{
		if (g_data.lst->content->type == I_D_INREDIR)
			if (is_meta_char() == 1)
				return (1);
		g_data.lst = g_data.lst->next;
	}
	return (0);
}

int	is_meta_char(void)
{
	if (g_data.lst->next->content->type == I_D_INREDIR)
		return (1);
	if (g_data.lst->next->content->type == I_INREDIR)
		return (1);
	if (g_data.lst->next->content->type == I_D_OUTREDIR)
		return (1);
	if (g_data.lst->next->content->type == I_OUTREDIR)
		return (1);
	if (g_data.lst->next->content->type == I_PIPE)
		return (1);
	if (g_data.lst->next->content->val[0] == ';')
		return (1);
	if (g_data.lst->next->content->val[0] == '&')
		return (1);
	return (0);
}

int	nb_here_doc(void)
{
	int		nb_hd;
	t_list	*lst;

	nb_hd = 0;
	lst = (*g_data.tokens);
	while (lst)
	{
		if (lst->content->type == I_D_INREDIR)
			nb_hd++;
		lst = lst->next;
	}
	return (nb_hd);
}

char	*here_doc_supply_loop(char *line, char *ret, char *exp, int i_lim)
{
	while (1)
	{
		line = readline("> ");
		here_doc_other_supply(line, ret);
		if ((ft_strncmp(line, g_data.limiters[i_lim], \
		ft_max((ft_strlen(line)), ft_strlen(g_data.limiters[i_lim]))) == 0))
		{
			i_lim++;
			if (!g_data.limiters[i_lim])
			{
				ret = ft_strjoin(ret, "\n");
				free(line);
				break ;
			}
		}
		else
		{
			exp = expand_str(line);
			ret = ft_strjoin(ret, exp);
			ret = ft_strjoin(ret, "\n");
			free(exp);
		}
	}
	return (ret);
}

char	*is_cmd_in_hd(char *tmp)
{
	if (g_data.lst->content->type != I_D_INREDIR)
	{
		tmp = g_data.lst->content->val;
		if (ft_strcmp(g_data.lst->content->val, "cat") == 1 && \
		g_data.lst->next->content->type == I_D_INREDIR)
			tmp = NULL;
	}
	return (tmp);
}
