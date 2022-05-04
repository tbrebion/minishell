/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:54:00 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/04 14:26:14 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	display_prompt(char **my_env)
{
	char	*cwd;
	char	*user_line;
	//char	*to_print;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	user_line = catch_user(my_env);
	while ((ft_strnstr(cwd, catch_username(user_line), ft_strlen(cwd))))
		cwd++;
	ft_printf("%s", cwd);
	ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}
