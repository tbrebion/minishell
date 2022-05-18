/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/18 14:25:26 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*catch_env_var(char *input, char **my_env)
{
	char	*ret;
	int		i;

	i = 0;
	while (!(ft_strnstr(my_env[i], input + 1, ft_strlen(input) - 1)))
		i++;
	ret = ft_strnstr(my_env[i], input + 1, ft_strlen(input) - 1);
	if (!ret)
		return (NULL); // ERROR
	i = 0;
	while (ret[i] != '=')
		i++;
	i++;
	return (ret + i);
}
