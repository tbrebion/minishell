/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stradd_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:28:51 by flcarval          #+#    #+#             */
/*   Updated: 2022/07/30 07:51:31 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*first(char c);

char	*stradd_char(char *str, char c)
{
	char	*res;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (first(c));
	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(str);
	return (res);
}

static char	*first(char c)
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}
