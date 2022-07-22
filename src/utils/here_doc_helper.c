/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:41:41 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/22 18:57:55 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_meta_char(void)
{
	while (g_data.lst->next)
	{
		if (g_data.lst->content->type == I_D_INREDIR)
			if(is_meta_char() == 1)
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
	t_list	*tmp;

	nb_hd = 0;
	tmp = g_data.lst;
	while (g_data.lst->next)
	{
		if (g_data.lst->content->type == I_D_INREDIR)
			nb_hd++;
		g_data.lst = g_data.lst->next;
	}
	g_data.lst = tmp;
	return (nb_hd);
}

// void	multi_limiter(void)
// {

// }
// void	multi_hd_supply(char *limiter, char *new_lim)
// {
// 	int nb _hd;

// 	nb_hd = nb_here_doc();
// 	if (nb_hd > 1)
// 		nb_hd--;
// }
