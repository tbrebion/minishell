/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:54:00 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/05 11:58:17 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	display_prompt(char **my_env)
{
	char	*cwd;
	char	*user_line;
	int		i;
	char	buff[4096 + 1];

	i = 0;
	cwd = getcwd(buff, 4096);
	user_line = catch_user(my_env);
	cwd = ft_strnstr(cwd, user_line + 5, ft_strlen(cwd));
	while (cwd[i] != '/')
		i++;
	i++;
	ft_printf("~/%s", cwd + i);
	ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}
