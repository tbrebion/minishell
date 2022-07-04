/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:42:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 10:28:19 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	env_len(char *str);
static char	*expand_str_supply(char *str);
static int	is_dollar(char *str);

char	*expand_str(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (is_dollar(str) != 0)
	{
		tmp = ft_strdup(str);
		free(str);
		str = expand_str_supply(tmp);
		free(tmp);
	}
	return (str);
}

static char	*expand_str_supply(char *str)
{
	int		i;
	char	*tmp;
	char	*ret;
	char	*res;
	char	*end;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (!str[i])
		return (NULL);
	end = ft_strdup(&str[i + env_len(&str[i])]);
	////////////////////////
	// ft_printf("[expand_str_supply] : end = [%s]\n", end);
	////////////////////////
	res = ft_strndup(str, i);
	tmp = ft_strndup(&str[i], env_len(&str[i]));
	ret = catch_env_var(tmp);
	res = ft_strjoin(res, ret);
	res = ft_strjoin(res, end);
	free(tmp);
	free(end);
	//////////////////////
	// ft_printf("\n[expand_str_supply] = %s\n\n", res);
	//////////////////////
	return (res);
}

static int	is_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

static int	env_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}
