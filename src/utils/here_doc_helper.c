/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:41:41 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/26 15:24:21 by flcarval         ###   ########.fr       */
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
	t_list	*lst;

	nb_hd = 0;
	lst = (*g_data.tokens);
	while (lst)
	{
		if (lst->content->type == I_D_INREDIR)
			nb_hd++;
		lst = lst->next;
	}
	/////////////////////////////////////
	// ft_printf("nb_hd = %d\n", nb_hd);
	/////////////////////////////////////
	return (nb_hd);
}

void	multi_limiter(void)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (nb_here_doc() < 1)
		return ;
	g_data.limiters = limiter_handler();
}

// void	multi_limiter(void)
// {
// 	int		j;

// 	j = 0;
// 	if (nb_here_doc() <= 1)
// 		return ;
// 	g_data.limiters = malloc(sizeof(char *) * nb_here_doc());
// 	while (j <= nb_here_doc())
// 	{
// 		while (g_data.lst->content->type != I_D_INREDIR)
// 			g_data.lst = g_data.lst->next;
// 		g_data.lst = g_data.lst->next;
// 		g_data.limiters[j] = ft_strdup(g_data.lst->content->val);
// 		ft_printf("lim[%d] : %s\n", j, g_data.limiters[j]);
// 		j++;
// 	}
// }
