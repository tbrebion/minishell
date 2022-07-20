/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:41:41 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/20 15:11:32 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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