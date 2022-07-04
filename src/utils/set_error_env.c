/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 16:48:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	set_error_env_supply(int *j, char *exp, char *err_stat);

void	set_error_env(void)
{
	int		j;
	char	*exp;
	char	*err_stat;
	char	*err_var;

	j = 0;
	err_var = ft_strdup("?=");
	err_stat = ft_itoa(g_data.error_status);
	exp = ft_strjoin(err_var, err_stat);
	while (g_data.my_env[j])
		if (set_error_env_supply(&j, exp, err_stat))
			return ;
	free(err_stat);
	g_data.my_env[j] = ft_strdup(exp);
	free(exp);
}

static int	set_error_env_supply(int *j, char *exp, char *err_stat)
{
	char	**spl;

	spl = ft_split(g_data.my_env[*j], '=');
	if (!ft_strncmp(spl[0], exp, ft_strlen(spl[0])) && \
		exp[ft_strlen(spl[0])] == '=')
	{
		free(g_data.my_env[*j]);
		g_data.my_env[*j] = ft_strdup(exp);
		free_split(spl);
		spl = NULL;
		free(err_stat);
		free(exp);
		return (1);
	}
	else
	{
		free_split(spl);
		spl = NULL;
	}
	(*j)++;
	return (0);
}
