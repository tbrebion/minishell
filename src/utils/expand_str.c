/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:42:14 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/03 15:48:53 by tbrebion         ###   ########.fr       */
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

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (!str[i])
		return (NULL);
	res = ft_strndup(str, i);
	tmp = ft_strndup(&str[i], env_len(&str[i]));
	ret = catch_env_var(tmp);
	res = ft_strjoin(res, ret);
	free(tmp);
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
