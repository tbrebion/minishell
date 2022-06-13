/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/13 16:39:52 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_varenv(/*t_data *data, */int i)
{
	int		j;
	char	**spl;
	char	*exp;
	int		k;
	int		t;

	j = 0;
	spl = NULL;
	if (!get_n_lst(data.Tokens, i + 1))
		return ;
	exp = get_n_lst(data.Tokens, i + 1)->content->val;
	while (data.my_env[j])
	{
		spl = ft_split(data.my_env[j], '=');
		t = 0;
		while (exp[ft_strlen(spl[0]) + t] == ' ')
			t++;
		if (exp[ft_strlen(spl[0]) + t] == '=' && t)
			return ;
		if (!ft_strncmp(spl[0], exp, ft_strlen(spl[0])) && \
			exp[ft_strlen(spl[0])] == '=')
		{
			free(data.my_env[j]);
			data.my_env[j] = ft_strdup(exp);
			k = -1;
			while (spl[++k])
				free(spl[k]);
			free(spl);
			return ;
		}
		j++;
	}
	data.my_env[j] = ft_strdup(exp);
}

static int	is_add(char *str);
static int	is_al_set(char *exp);
static void	add_var(char *exp);
static void	set_var(char *exp);

void	export_varenv(/*t_data *data, */int i)
{
	char	**spl;
	int		j;
	char	*exp;

	j = 0;
	if (!get_n_lst(data.Tokens, i + 1))
		return ;
	exp = get_n_lst(data.Tokens, i + 1)->content->val;
	if (is_add(exp))
	{
		add_var(exp);
	}
	else
	{
		set_var(exp);
	}
}

static int	is_add(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == '+' && str[i + 1] == '=')
			return (i + 2);
		i++;
	}
	return (-1);
}

static int	is_al_set(char *exp)
{
	int		i;
	char	**spl;

	i = 0;
	while (data.my_env[i])
	{
		spl = ft_split(data.my_env[i], "=");
		if (!ft_strncmp(spl[0], exp, ft_strlen(spl[0])))
			return (i);
		free_split(spl);
		i++;
	}
	return (-1);
}

static void	add_var(char *exp)
{
	int		i;
	char	*tmp;

	i = is_al_set(exp);
	if (i == -1)
	{
		i = 0;
		while (data.my_env[i])
			i++;
		
	}
	else
		tmp = ft_strdup(data.my_env[i]);
	data.my_env[i] =
}
