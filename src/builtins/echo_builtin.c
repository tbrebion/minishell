/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 01:26:03 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/28 15:58:43 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	echo_empty(void);
static void	set_n_i(int *n, int *i, int mod);
static void	echo_supply_loop(int i, int *j);
static int	is_n_param(char *str);

int	echo_builtin(int i)
{
	char	*nl;
	int		n;
	int		j;

	if (!(get_n_lst(g_data.tokens, i + 1)))
		return (echo_empty());
	set_n_i(&n, &i, is_n_param(get_n_lst(g_data.tokens, i + 1)->content->val));
	if (!n)
		nl = "\n";
	else
		nl = "";
	j = 0;
	while (get_n_lst(g_data.tokens, i + j) && \
		(get_n_lst(g_data.tokens, i + j)->content->type == I_LITERAL || \
		get_n_lst(g_data.tokens, i + j)->content->type == I_D_QUOTE || \
		get_n_lst(g_data.tokens, i + j)->content->type == I_S_QUOTE))
	{
		if (is_n_param(get_n_lst(g_data.tokens, i + j++)->content->val))
			continue ;
		echo_supply_loop(i, &j);
	}
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
		*i += 1;
	}
	else
	{
		*n = 1;
		*i += 1;
	}
}

static void	echo_supply_loop(int i, int *j)
{
	if (get_n_lst(g_data.tokens, i + *j))
		ft_printf("%s", get_n_lst(g_data.tokens, i + *j)->content->val);
	(*j)++;
	if (get_n_lst(g_data.tokens, i + *j) && \
	(get_n_lst(g_data.tokens, i + *j)->content->type == I_LITERAL || \
	get_n_lst(g_data.tokens, i + *j)->content->type == I_D_QUOTE || \
	get_n_lst(g_data.tokens, i + *j)->content->type == I_S_QUOTE))
		ft_printf(" ");
}

static int	is_n_param(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
