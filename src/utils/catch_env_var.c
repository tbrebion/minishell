/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/31 14:45:55 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*catch_env_var(char *input/*, t_data *data*/)
{
	char	*ret;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tab = NULL;
	ret = NULL;
	if (ft_strlen(input) == 1)
		return (NULL);
	while (data.my_env[i] && !(ft_strnstr(data.my_env[i], input + 1, ft_strlen(input) - 1)))
		i++;
	if (data.my_env[i])
	{
		tab = ft_split(data.my_env[i], '=');
		ret = ft_strnstr(data.my_env[i], input + 1, ft_strlen(input));
	}
	if (data.my_env[i] && (ft_strncmp(tab[0], input + 1, ft_strlen(tab[0])) != 0))
	{
		while (tab[++j])
			free(tab[j]);
		free(tab);
		return (NULL);
	}
	if (!ret)
		return (NULL);
	i = 0;
	while (ret[i] != '=')
		i++;
	i++;
	if (tab)
	{
		while (tab[++j])
			free(tab[j]);
		free(tab);
	}
	return (ret + i);
}
