/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:26:03 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/03 15:56:23 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
echo function takes *str as the string to output
and n so n = 1 -> print w/ \n (n = 0 -> print w/o \n)
*/

// ! SEGFAULT  when no args

int	echo_builtin(int i)
{
	char	*nl;
	char	*ret;
	int		n;
	int		j;

	if (!(get_n_lst(data.Tokens, i + 1)))
	{
		write(1, "\n", 1);
		return (-1);
	}
	if ((ft_strncmp(get_n_lst(data.Tokens, i + 1)->content->val, "-n", 2) == 0))
	{
		n = 0;
		i += 2;
	}
	else
	{
		n = 1;
		i += 1;
	}
	if (n)
		nl = "\n";
	else
		nl = "";
	j = 0;
	while (get_n_lst(data.Tokens, i + j) && \
		(get_n_lst(data.Tokens, i + j)->content->type == I_LITERAL || \
		get_n_lst(data.Tokens, i + j)->content->type == I_D_QUOTE || \
		get_n_lst(data.Tokens, i + j)->content->type == I_S_QUOTE))
	{
		ret = NULL;
		if (get_n_lst(data.Tokens, i + j)->content->type != I_S_QUOTE)
			ret = catch_env_var(get_n_lst(data.Tokens, i + j)->content->val);
		if (ret != NULL)
			ft_printf("%s", ret);
		else
			ft_printf("%s", get_n_lst(data.Tokens, i + j)->content->val);
		j++;
		if (get_n_lst(data.Tokens, i + j) && \
		(get_n_lst(data.Tokens, i + j)->content->type == I_LITERAL || \
		get_n_lst(data.Tokens, i + j)->content->type == I_D_QUOTE || \
		get_n_lst(data.Tokens, i + j)->content->type == I_S_QUOTE))
			ft_printf(" ");
	}
	ft_printf("%s", nl);
	return (0);
}
