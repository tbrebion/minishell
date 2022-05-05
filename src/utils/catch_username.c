/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_username.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:56:36 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/05 11:59:38 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*catch_user(char **my_env)
{
	int	i;

	i = -1;
	while (my_env[++i])
	{
		if (ft_strnstr(my_env[i], "USER", 4))
			return (my_env[i]);
	}
	return (NULL);
}

/*char	*catch_username(char *user_line)
{
	int	i;

	i = 0;
	while (i < 5)
		user_line++;
	return (user_line);
}*/
