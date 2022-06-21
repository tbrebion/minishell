/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/06/21 16:57:21 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_add(char *exp);
static int	is_al_set(char *exp);
static void	add_var(char *exp);
static void	set_var(char *exp);
static char	*remove_plus(char *exp);
static int	exp_check(char *exp);

void	export_varenv(/*t_data *data, */int i)
{
	int		j;
	char	*exp;

	j = 0;
	if (!get_n_lst(data.Tokens, i + 1))
		return ;
	exp = get_n_lst(data.Tokens, i + 1)->content->val;
	if (!exp_check(exp))
		return ;
	if (is_add(exp) != -1)
	{
		if (is_al_set(exp) != -1)
			add_var(exp);
		else
			set_var(remove_plus(exp));
	}
	else
	{
		set_var(exp);
	}
}

static int	is_add(char *exp)
{
	int	i;

	i = 0;
	while (exp[i + 1])
	{
		if (exp[i] == '+' && exp[i + 1] == '=')
		{
			return (i + 2);
		}
		i++;
	}
	return (-1);
}

static int	is_al_set(char *exp)
{
	int		i;
	char	**spl;
	char	**tmp;

	i = 0;
	tmp = ft_split(exp, '=');
	while (data.my_env[i])
	{
		spl = ft_split(data.my_env[i], '=');
		if (ft_strcmp(spl[0], remove_plus(tmp[0])))
		{
			free_split(tmp);
			return (i);
		}
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
	tmp = ft_split(exp, '=')[1];
	if (i == -1)
	{
		i = 0;
		while (data.my_env[i])
			i++;
		data.my_env[i] = ft_strdup(exp);
	}
	else
		data.my_env[i] = ft_strjoin(data.my_env[i], tmp);
	free(tmp);
}

static void	set_var(char *exp)
{
	int	i;

	i = is_al_set(exp);
	if (i == -1)
	{
		i = 0;
		while (data.my_env[i])
			i++;
	}
	data.my_env[i] = ft_strdup(exp);
}

static char	*remove_plus(char *exp)
{
	int	i;

	i = 0;
	while (exp[i])
	{
		if (exp[i] == '+' /*&& exp[i + 1] == '='*/)
		{
			if (!exp[i + 1])
			{
				exp[i] = '\0';
				return (exp);
			}
			while (exp[i])
			{
				exp[i]= exp[i + 1];
				i++;
			}
			return (exp);
		}
		i++;
	}
	return (exp);
}

static int	exp_check(char *exp)
{
	int	i;

	i = 0;
	while (exp[i])
	{
		if (exp[i] == '=' && exp[i + 1] == '=')
		{
			ft_printf("'=': not a valid identifier\n");
			return (0);
		}
		i++;
	}
	return (1);
}
