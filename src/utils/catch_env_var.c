/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:25:04 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/19 15:03:09 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*catch_env_var(char *input, char **my_env)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (my_env[i] && !(ft_strnstr(my_env[i], input + 1, ft_strlen(input) - 1)))
		i++;
	if (my_env[i])
		ret = ft_strnstr(my_env[i], input + 1, ft_strlen(input) - 1);
	if (!ret)
		return (NULL); // ERROR
	i = 0;
	while (ret[i] != '=')
		i++;
	i++;
	return (ret + i);
}
