/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:48:13 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/29 13:05:48 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_tok_list(void)
{
	t_list	*lst;

	lst = (*g_data.tokens);
	ft_printf("\n");
	while (lst)
	{
		ft_printf("%s[%s]%s[%d]%s", "\x1B[31m", lst->content->val, "\x1B[34m", lst->content->type, "\x1B[0m");
		lst = lst->next;
	}
	ft_printf("\n\n");
}
