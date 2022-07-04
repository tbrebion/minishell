/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:58:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 11:52:25 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_add(char *exp);
int			is_al_set(char *exp);
static char	*remove_plus(char *exp);
static int	exp_check(char *exp);

void	export_varenv(int i)
{
	int		j;
	char	**spl;
	char	*exp;

	j = 0;
	spl = NULL;
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

int	is_al_set(char *exp)
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
			free_split(spl);
			return (i);
		}
		free_split(spl);
		i++;
	}
	free_split(tmp);
	return (-1);
}

static char	*remove_plus(char *exp)
{
	int	i;

	i = 0;
	while (exp[i])
	{
		if (exp[i] == '+')
		{
			if (!exp[i + 1])
			{
				exp[i] = '\0';
				return (exp);
			}
			while (exp[i])
			{
				exp[i] = exp[i + 1];
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
