/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:26:03 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	echo_empty(void);
static void	set_n_i(int *n, int *i, int mod);
static void	echo_supply_loop(int i, int *j);

int	echo_builtin(int i)
{
	char	*nl;
	int		n;
	int		j;

	if (!(get_n_lst(g_data.Tokens, i + 1)))
		return (echo_empty());
	set_n_i(&n, &i, (ft_strncmp(get_n_lst(g_data.Tokens, i + 1)->content->val, \
		"-n", 2)));
	if (n)
		nl = "\n";
	else
		nl = "";
	j = 0;
	while (get_n_lst(g_data.Tokens, i + j) && \
		(get_n_lst(g_data.Tokens, i + j)->content->type == I_LITERAL || \
		get_n_lst(g_data.Tokens, i + j)->content->type == I_D_QUOTE || \
		get_n_lst(g_data.Tokens, i + j)->content->type == I_S_QUOTE))
		echo_supply_loop(i, &j);
	ft_printf("%s", nl);
	return (0);
}

static int	echo_empty(void)
{
	write(1, "\n", 1);
	return (-1);
}

static void	set_n_i(int *n, int *i, int mod)
{
	if (!mod)
	{
		*n = 0;
		*i += 2;
	}
	else
	{
		*n = 1;
		*i += 1;
	}
}

static void	echo_supply_loop(int i, int *j)
{
	char	*ret;

	ret = NULL;
	if (get_n_lst(g_data.Tokens, i + *j)->content->type != I_S_QUOTE)
		ret = catch_env_var(get_n_lst(g_data.Tokens, i + *j)->content->val);
	if (ret != NULL)
		ft_printf("%s", ret);
	else
		ft_printf("%s", get_n_lst(g_data.Tokens, i + *j)->content->val);
	(*j)++;
	if (get_n_lst(g_data.Tokens, i + *j) && \
	(get_n_lst(g_data.Tokens, i + *j)->content->type == I_LITERAL || \
	get_n_lst(g_data.Tokens, i + *j)->content->type == I_D_QUOTE || \
	get_n_lst(g_data.Tokens, i + *j)->content->type == I_S_QUOTE))
		ft_printf(" ");
}
