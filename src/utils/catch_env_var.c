/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/07/04 15:49:55 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*catch_supply(char *input, char **tab, int *i, int *j);
static char	*return_catched(char **tab, char *ret, int i);

char	*catch_env_var(char *input)
{
	char	*ret;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tab = NULL;
	if (ft_strlen(input) == 1)
		return (NULL);
	while (data.my_env[i] && !(ft_strnstr(data.my_env[i], \
		input + 1, ft_strlen(input) - 1)))
		i++;
	if (!data.my_env[i] && input[0] != '$')
		return (NULL);
	if (!data.my_env[i] && input[0] == '$')
	{
		ret = ft_strdup("\0");
		return (ret);
	}
	ret = catch_supply(input, tab, &i, &j);
	return (return_catched(tab, ret, i));
}

static char	*catch_supply(char *input, char **tab, int *i, int *j)
{
	char	*ret;

	ret = NULL;
	if (data.my_env[*i])
	{
		tab = ft_split(data.my_env[*i], '=');
		ret = ft_strnstr(data.my_env[*i], input + 1, ft_strlen(input));
	}
	if (data.my_env[*i] && \
	(ft_strncmp(tab[0], input + 1, ft_strlen(tab[0])) != 0))
	{
		while (tab[++(*j)])
			free(tab[*j]);
		free(tab);
		return (NULL);
	}
	if (!ret)
		return (NULL);
	*i = 0;
	while (ret[*i] != '=')
		(*i)++;
	(*i)++;
	free_split(tab);
	return (ret);
}

static char	*return_catched(char **tab, char *ret, int i)
{
	if (tab)
		free_split(tab);
	if (ret == NULL)
		return (NULL);
	return (ret + i);
}
